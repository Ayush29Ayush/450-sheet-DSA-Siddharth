class Solution
{
	public:
	
	void DFSTopo(vector<int> adj[], int u, vector<bool> &visited, stack<int> &st)
	{
	    // jis node pe aaye usko visited mark karo
	    visited[u] = true;
	    
	    // pehle DFS call karke bacho ko daalo stack mein then last mein parent ko daalna
	    // HINT -> for loop khatam hone ke baad stack mein push karna node ko
	    for(auto v : adj[u])
	    {
	        if(!visited[v])
	        {
	            DFSTopo(adj,v,visited,st);
	        }
	    }
	    
	    // ab "u" ko stack mein daaldo
	    st.push(u);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> visited(V,false);
	    stack<int> st;
	    
	    for(int u=0; u<V; u++)
	    {
	        if(!visited[u])
	        {
	            DFSTopo(adj,u,visited,st);
	        }
	    }
	    
	    // ab stack se maal nikalo
	    vector<int> result;
	    
	    while(!st.empty())
	    {
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
	}
};