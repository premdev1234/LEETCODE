class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<vector<int>> s_(129) , t_(129);
        for(int i = 0 ;  i< s.length() ; ++i){
            s_[s[i]].push_back(i);
            t_[t[i]].push_back(i);
            if(s_[s[i]] != t_[t[i]]) return false;
        }
        return true;
    }
};