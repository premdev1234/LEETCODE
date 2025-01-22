class TrieNode {
public:
    TrieNode* children[26];
    int score;

    TrieNode() : score(0) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
            node->score++;
        }
    }

    int getWordScore(TrieNode* root, const string& word) {
        TrieNode* node = root;
        int totalScore = 0;
        for (char ch : word) {
            int index = ch - 'a';
            node = node->children[index];
            totalScore += node->score;
        }
        return totalScore;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            insertWord(root, word);
        }
        vector<int> answer;
        for (const string& word : words) {
            answer.push_back(getWordScore(root, word));
        }
        return answer;
    }
};
