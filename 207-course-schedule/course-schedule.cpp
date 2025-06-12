class Solution {
public:
    bool isCycle(int node, const unordered_map<int, vector<int>>& graph, 
                 bitset<2001>& visited, bitset<2001>& inStack) {
        visited[node] = true;
        inStack[node] = true;

        auto it = graph.find(node);
        if (it != graph.end()) {
            for (int child : it->second) {
                if (!visited[child]) {
                    if (isCycle(child, graph, visited, inStack)) return true;
                } else if (inStack[child]) {
                    return true; // back edge → cycle
                }
            }
        }

        inStack[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (const auto& pre : prerequisites) 
            graph[pre[1]].push_back(pre[0]); // edge: course → dependent

        bitset<2001> visited, inStack;
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (isCycle(i, graph, visited, inStack)) return false;
            }
        }
        return true;
    }
};
