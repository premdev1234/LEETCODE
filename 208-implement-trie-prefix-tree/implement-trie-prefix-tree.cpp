struct node {
    char data;
    bool isTerminal;
    node* children[26];

    node(char c) : data(c), isTerminal(false) {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Trie {
public:
    node* root;

    Trie() {
        root = new node('\0'); // Root with dummy character
    }

    void insert(string word) {
        node* trie = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (trie->children[index] == nullptr) {
                trie->children[index] = new node(ch);
            }
            trie = trie->children[index];
        }
        trie->isTerminal = true;
    }

    bool search(string word) {
        node* trie = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (trie->children[index] == nullptr)
                return false;
            trie = trie->children[index];
        }
        return trie->isTerminal;
    }

    bool startsWith(string prefix) {
        node* trie = root;
        for (char ch : prefix) {
            int index = ch - 'a';
            if (trie->children[index] == nullptr)
                return false;
            trie = trie->children[index];
        }
        return true;
    }
};
