//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void BFS(unordered_map<int,vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result)
    {
        queue<int> que;
        
        que.push(u);
        visited[u] = true;
        // Jis node ya Vertice pe ho usko pehle result mein daaldo then aage ka DFS call karna
        result.push_back(u);
        
        // BFS ka internal working using queue
        while(!que.empty())
        {
            int u = que.front();
            que.pop();
            
            for(auto v : adj[u])
            {
                if(!visited[v])
                {
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
  
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        // Code here
        
        unordered_map<int,vector<int>> adj;
        
        // Adjecency list banao
        for(int u=0; u<V; u++)
        {
            for(auto v=mp[u].begin(); v != mp[u].end(); v++)
            {
                adj[u].push_back(*v);
            }
        }
        
        vector<int> result;
        vector<bool> visited(V,false);
        
        // BFS call kardo
        BFS(adj,0,visited,result);
        
        return result;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends