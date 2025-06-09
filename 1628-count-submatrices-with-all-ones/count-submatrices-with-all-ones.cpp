class Solution {
public:
    int solveTopLeft(int s_i,int s_j,vector<vector<int>>&mat)
    {
        int m=mat.size();
        int n=mat[0].size();
        int count=0;
        int lastZeroColumn=n;
        for(int i=s_i;i<m;i++)
        {
            for(int j=s_j;j<lastZeroColumn;j++)
            {
                if(mat[i][j])  // I have handled  last row zero with help of s_j column value..think you will get it 
                    count++;
                else
                {
                    lastZeroColumn=j;
                    break;
                }
            }
             if( lastZeroColumn == s_j) // making it more clear
                return  count;

        }
        return count;
    }
    int numSubmat(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=solveTopLeft(i,j,mat);
            }
        }
        return ans;
        
    }
};