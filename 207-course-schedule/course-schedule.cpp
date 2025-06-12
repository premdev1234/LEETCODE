class Solution {
public:
    void dfs(vector<vector<int>> &adj,vector<int> &visited,vector<int> &visi,int temp,bool &flag)
    {
        if(visited[temp] != 0)
        {
            return;
        }
        visi[temp]=1;
        visited[temp]++;
        for(int i=0;i<adj[temp].size();i++)
        {
            if(visi[adj[temp][i]] == 0)
            {
                dfs(adj,visited,visi,adj[temp][i],flag);
            }
            else
            {
                flag=true;
            }
        }
        visi[temp]=0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) 
    {
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prereq.size();i++)
        {
            adj[prereq[i][0]].push_back(prereq[i][1]);
        }
        vector<int> visited(numCourses,0);
        vector<int> visi(numCourses,0);
        bool flag=false;
        for(int i =0;i<visited.size();i++)
        {
            if(visited[i] == 0)
            {
                dfs(adj,visited,visi,i,flag);
                if(flag == true)
                {
                    return false;
                }
            }
        }
        return true;
    }
};