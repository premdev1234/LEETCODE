class Solution {
public:
    struct node{
        node* children[26];
        node(){
            for(int i = 0 ; i < 26 ; ++i) children[i] = nullptr;
        }
    };
    int dfs(node* node, int depth) {
        bool leaf = true;
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            if(node->children[i]) {
                leaf = false;
                ans += dfs(node->children[i], depth + 1);
            }
        }

        if(leaf)
            return depth + 1;

        return ans;
    }
    int minimumLengthEncoding(vector<string>& words) {
        unordered_set<string> unique_words(words.begin(),words.end());
        node* root = new node();
        for(auto word: unique_words){
            reverse(word.begin(),word.end());
            node* curr = root ;
            for(char c : word){
                int idx = c - 'a';
                if(curr->children[idx] == nullptr) curr->children[idx] = new node();
                curr = curr->children[idx];
            }
        }
        int ans = dfs(root,0);
        return ans ;
    }
};