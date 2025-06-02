struct Node {
    Node* child[2];
    Node(){
        child[0] = child[1] = nullptr;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();

        // Step 1: Build the Trie
        for (int num : nums) {
            Node* node = root;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (!node->child[bit]) {
                    node->child[bit] = new Node();
                }
                node = node->child[bit];
            }
        }

        // Step 2: Find maximum XOR
        int res = 0;
        for (int num : nums) {
            Node* node = root;
            int curr = 0;
            for (int i = 31; i >= 0; --i) {
                int bit = (num >> i) & 1;
                if (node->child[1 - bit]) {
                    curr |= (1 << i);              
                    node = node->child[1 - bit];   
                } else {
                    node = node->child[bit];       
                }
            }
            res = max(res, curr);
        }

        return res;
    }
};
