class Solution {
public:
    string maximumXor(string s, string t) {
        int z = 0 , o = 0 ;
        for(char c : t){
            if(c == '0')z++;
            else o++;
        }
        t = "";
        for(char c: s){
            if(c == '0'){
                if(o >0){
                    t += '1';
                    --o;
                } else{
                    t+='0';
                    --z;
                }
            }else{
                if(z > 0){
                    t += '1';
                    --z;
                }else{
                    t += '0';
                    --o;
                }
            }
        }
        return t ;
    }
};