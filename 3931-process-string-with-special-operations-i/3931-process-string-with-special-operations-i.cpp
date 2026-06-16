class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(char c : s){
            if( c >= 'a' && c <= 'z') result += c ;
            else if(c == '*' && result.size()) result.pop_back();
            else if(c == '%') reverse(result.begin(),result.end());
            else result += result ;
        }
        return result ;
    }
};