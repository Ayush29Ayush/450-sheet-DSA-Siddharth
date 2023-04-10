class Solution {
  public:
    bool isCycleDFS(vector<int> adj[], int u, vector<bool> &visited, int parent)
    {
        // node ke pass aye toh mark it visited
        visited[u] = true;
        
        for(auto v : adj[u])
        {
            if(v==parent)
                continue;
            
            // agar parent nahi hai but already visited hai means cycle found
            if(visited[v]==true)
                return true;
                
            // agar kahi bhi kuch return nahi hua toh do further DFS
            if(isCycleDFS(adj,v,visited,u))
                return true;
        }
        
        return false;
    }
  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Dont make Adjecency list yourself using map. Lets use the given one
        
        vector<bool> visited(V,false);
        
        for(int u=0; u<V; u++)
        {
            // Starting node ka parent = -1
            if(!visited[u] && isCycleDFS(adj, u, visited, -1)==true)
            {
                return true;
            }
        }
        
        // agar kahi par bhi true return nahi hau toh return false
        return false;
    }
};