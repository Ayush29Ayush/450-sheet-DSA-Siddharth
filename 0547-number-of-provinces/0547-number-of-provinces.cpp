//! Approach1 => Khudka Adjecency list banao and DFS se solve kardo
class Solution {
public:
    void DFS(unordered_map<int,vector<int>> &adj, int u, vector<bool> &visited)
    {
        // visited mark karo u ko
        visited[u] = true;
        
        // Ab DFS lagao u ke adj list pe
        for(auto v : adj[u])
        {
            if(!visited[v])
            {
                DFS(adj,v,visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<bool> visited(n,false);
        
        // 1. Make graph by making adjecency list. i means u and j means v
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(isConnected[i][j]==1) // condition given in ques
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        // 2. Ab bass DFS call lagado on adj list
        // 1 <= n <= 200 given in ques toh for(int u=1; u<=n; u++) bhi kar sakte they
        for(int u=0; u<n; u++)
        {
            if(!visited[u])
            {
                DFS(adj,u,visited);
                count++;
            }
        }
        
        return count;
    }
};

//Approach-2 : [ Using DFS - Using given input graph]
// class Solution {
// public:
//     int n;
//     void dfs(vector<vector<int>> &adj, int u, vector<bool>& visited) {
//         visited[u] = true;
        
//         //Visit neighbours
//         for(int v = 0; v < n; v++) {
//             if(adj[u][v] == 1 && !visited[v]) {
//                 dfs(adj, v, visited);
//             }
//         }
//     }
    
    
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         n = isConnected.size();
        
//         vector<bool> visited(n, false);
//         int count = 0;
        
//         for(int i = 0; i<n; i++) {
//             if(!visited[i]) {
//                 count++;
//                 dfs(isConnected, i, visited);
//             }
//         }
        
//         return count;
        
//     }
// };
