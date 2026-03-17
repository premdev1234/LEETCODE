class Solution {
public:
    string longestPrefix(string s) {
        int n = (int)s.size();
        vector<int>pi(n,0);
        for(int i = 1 ; i < n  ; ++i){
            int j = pi[i-1];
            while(j > 0 and s[i] != s[j])j=pi[j-1];
            if(s[i] ==  s[j])++j;
            pi[i] = j ;
        }
        if(pi[n-1] == 0)return "";
        return s.substr(0,pi[n-1]);
    }
};