
//! This entire code is the Kahn's Algorithm
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[]) 
	{
	    vector<int> indegree(N,0);
	    queue<int> q;
	    vector<int> result;
	    
	    // 1. Fill the indegree vector 
	    for(int u=0; u<N; u++)
	    {
	        for(auto v : adj[u])
	        {
	            indegree[v]++;
	        }
	    }
	    
	    
	    // 2. Those who have indegree==0, push to stack first
	    for(int i=0; i<N; i++)
	    {
	        if(indegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    // 3. Now apply BFS
	    while(!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        result.push_back(u);
	        
	        for(auto v : adj[u])
	        {
	            indegree[v]--;
	            
	            if(indegree[v]==0)
	            {
	                q.push(v);
	            }
	        }
	        
	    }
	    
	    return result;
	}
};