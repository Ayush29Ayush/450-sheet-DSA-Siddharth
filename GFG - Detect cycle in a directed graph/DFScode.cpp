class Solution {
  public:
  
    bool isCycleDFS(vector<int> adj[], int u, vector<int> &visited, vector<int> &inRecursion)
    {
        // jis node pe aaye, usko visited and inRecursion ke liye true mark kardo
        visited[u] = true;
        inRecursion[u] = true;
        
        // ab iss U ke liye Adjecency list mein jitne bhi V hai, unpe DFS lagao if not visited
        for(auto v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(visited[v] == true && inRecursion[v] == true)
                return true;
        }
        // agar kahi pe bhi true nahi hua return then iss recursion mein nahi hai so vapis inRecursion ko false kardo
        inRecursion[u] = false;
        return false;
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> visited(V,false);
        vector<int> inRecursion(V,false);
        
        for(int u=0; u<V; u++)
        {
            // agar for loop ka node pehle se visited nahi hai and isCycleDFS is true then cycle exists
            if(!visited[u] && isCycleDFS(adj,u,visited,inRecursion))
            {
                return true;
            }
        }
        
        return false;
    }
};