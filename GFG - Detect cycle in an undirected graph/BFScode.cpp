class Solution {
  public:
    bool isCycleBFS(vector<int> adj[], int u, vector<bool>& visited) {
        queue<pair<int, int>> que;
        
        // present node ko visited mark kardo and push it to queue
        que.push({u,-1});
        visited[u] = true;
        
        // Now start doing BFS
        while(!que.empty())
        {
            pair<int,int> P = que.front();
            que.pop();
            
            int u = P.first;
            int parent = P.second;
            
            for(auto v : adj[u])
            {
                if(visited[v]==false)
                {
                    // agar pehle se visited nahi hai yeh node toh visited mark karo and push it to queue
                    visited[v]=true;
                    que.push({v,u}); // {node,parent} ko push kiya
                }
                else if(visited[v]==true && v!=parent)
                {
                    // node visited bhi hai but parent nahi hai means cycle hai so return true
                    return true;
                }
            }
        }
        // cycle nahi mila toh return false
        return false;
    }

  
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Dont make Adjecency list yourself using map. Lets use the given one
        
        vector<bool> visited(V,false);
        
        for(int u=0; u<V; u++)
        {
            // Starting node ka parent = -1
            if(!visited[u] && isCycleBFS(adj, u, visited)==true)
            {
                return true;
            }
        }
        
        // agar kahi par bhi true return nahi hau toh return false
        return false;
    }
};