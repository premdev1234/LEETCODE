class Solution {
public:
    bool checkValidString(string s) {
        int minbal=0,maxbal=0;
        for(char &x:s){
            if(x=='(') minbal++ ,  maxbal++;
            else if(x==')') minbal-- , maxbal--;
            else minbal-- , maxbal++;
            if(minbal<0) minbal=0;
            if(maxbal<0) return false;
        }
        return minbal==0;
    }
};