class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        // if(s1.length() == s2.length()) return s1==s2 ;
        int m =  s1.length() , n = s2.length();
        array<int,26> a = {} , b = {};
        for(int i = 0 ; i< m ;++i){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        if(a == b) return true;
        for(int i = m ;  i< n ; ++i){
            b[s2[i]-'a']++;
            b[s2[i-m]-'a']--;
            if(a == b) return true;
        }
        return false;
    }
};