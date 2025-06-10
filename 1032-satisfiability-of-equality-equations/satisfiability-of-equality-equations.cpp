class Solution {
public:
    int find(vector<int>&disjoint,int u){
        if(disjoint[u]==-1)return u;
        return disjoint[u]=find(disjoint,disjoint[u]);

    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>disjoint(26,-1);
        for(int i=0;i<equations.size();i++)
        {      
           
            if(equations[i][1]=='=')
            {
                 int px=find(disjoint,equations[i][0]-'a');
            int py=find(disjoint,equations[i][3]-'a');

             if(px!=py)disjoint[px]=py;
                  
            }
        }
          for(int i=0;i<equations.size();i++)
        {   
            if(equations[i][1]=='!')
            {
                int px=find(disjoint,equations[i][0]-'a');
                int py=find(disjoint,equations[i][3]-'a');
                if(px==py)return false;

            }
    }
    return true;
    }
};