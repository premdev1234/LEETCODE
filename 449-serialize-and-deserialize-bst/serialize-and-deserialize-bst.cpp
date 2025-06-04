class BitWriter {
    vector<uint8_t> buffer;
    int currBit = 0;
    uint8_t current = 0;

public:
    void writeBits(int val, int bits) {
        while (bits--) {
            current |= ((val >> bits) & 1) << (7 - currBit);
            if (++currBit == 8) {
                buffer.push_back(current);
                current = 0;
                currBit = 0;
            }
        }
    }

    string getString() {
        if (currBit > 0) buffer.push_back(current); // flush remaining bits
        return string(buffer.begin(), buffer.end());
    }

    int totalBits() const {
        return (int)buffer.size() * 8 + currBit;
    }
};

class BitReader {
    const string& data;
    int pos = 0, currBit = 0;
    int totalBits;

public:
    BitReader(const string& d) : data(d) {
        totalBits = (int)d.size() * 8;
    }

    int readBits(int bits) {
        int val = 0;
        while (bits--) {
            if (pos >= data.size()) return -1;  // EOF
            val <<= 1;
            val |= ((data[pos] >> (7 - currBit)) & 1);
            if (++currBit == 8) {
                currBit = 0;
                pos++;
            }
        }
        return val;
    }

    int remBits() const {
        return totalBits - (pos * 8 + currBit);
    }
};
class Codec {
public:
    void serializeNode(TreeNode* node, BitWriter& bw) {
        if (!node) return;

        // Store presence of left and right child
        bw.writeBits(node->left ? 1 : 0, 1);
        bw.writeBits(node->right ? 1 : 0, 1);

        // Store 16-bit node value
        bw.writeBits(node->val, 16);

        // Recursively serialize children
        serializeNode(node->left, bw);
        serializeNode(node->right, bw);
    }

    string serialize(TreeNode* root) {
        BitWriter bw;
        serializeNode(root, bw);
        return bw.getString();
    }

    TreeNode* deserializeNode(BitReader& br) {
        if (br.remBits() < 18) return nullptr;

        bool hasLeft = br.readBits(1);
        bool hasRight = br.readBits(1);
        int val = br.readBits(16);

        TreeNode* root = new TreeNode(val);
        if (hasLeft) root->left = deserializeNode(br);
        if (hasRight) root->right = deserializeNode(br);
        return root;
    }

    TreeNode* deserialize(string data) {
        BitReader br(data);
        return deserializeNode(br);
    }
};
