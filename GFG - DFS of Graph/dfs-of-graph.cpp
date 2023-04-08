//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void DFS(unordered_map<int,vector<int>> &adj, int u, vector<bool> &visited, vector<int> &result)
    {
        // base case for visited
        if(visited[u]==true)
            return;
        // if not visited then mark this visited
        visited[u] = true;
        
        // Jis node ya Vertice pe ho usko pehle result mein daaldo then aage ka DFS call karna
        result.push_back(u);
        
        // Now yahan ka kaam ho gaya so do further DFS traversal
        // int &v : adj[u] means =>     0->1,2 and here 0 is u and 1,2 are v
        for(auto v : adj[u])
        {
            // agar v visited nahi hai toh hi DFS lagega else infinite loop mein code phas jayega
            if(!visited[v])
            {
                DFS(adj,v,visited,result);
            }
        }
        
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> mp[]) {
        
        // vector<int> mp[] is a 2D matrix
        unordered_map<int,vector<int>> adj;
        
        // Adjecency List banao
        for(int u=0; u<V; u++)
        {
            for(auto v=mp[u].begin(); v!=mp[u].end(); v++)
            {
                adj[u].push_back(*v);
            }
        }
        
        vector<int> result;
        vector<bool> visited(V,false);
        
        DFS(adj,0,visited,result);
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends