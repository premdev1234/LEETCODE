class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::vector<bool> lower(26,false) , upper(26,0) , can(26,true);
        for(char c : word){
            if( 'A' <= c and c <= 'Z' ){
                int index = c - 'A'; 
                upper[c-'A'] = true ;
            }
            if( 'a' <= c and c <= 'z' ){
                int index = c - 'a';
                lower[index] = true ;
                if(upper[index]) can[index] = false ;   
            }
        }
        int cnt = 0 ;
        for(int i = 0 ; i < 26 ; ++i){
            if(can[i] == true  && upper[i] == true && lower[i] == true){
                cnt++;
            }
        }
        return cnt ;
        
    }
};