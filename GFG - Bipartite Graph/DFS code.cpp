class Solution {
public:
    bool checkBipartiteDFS(vector<int>adj[], int U, vector<int> &color, int currColor)
    {
        // Jis U pe aaye ho, usko color dedo
        color[U] = currColor;
        
        // ab DFS lagake adjecent nodes pe jao
        for(int &v : adj[U])
        {
            // agar curr wale node aur adj node ka color same aaya means bipartite not possible
            if(color[v] == color[U])
                return false;
            
            // agar non visited hai toh
            if(color[v]==-1)
            {
                // dusra color likhne ka line
                int colorOfV = 1 - currColor;
            
                if(checkBipartiteDFS(adj,v,color,colorOfV)==false)
                    return false;
            }
            
            // agar visited bhi hai v and color bhi U se same nahi hai toh last mein true return ho jayega
        }
        
        // agar false pehle kahi return nahi hua means true return hue jaa raha hai, so return true
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    
	    // this will also work as isVisited vector
	    vector<int> color(V,-1); // means no color alloted in the start
	    
	    // Lets take red = 1 and green = 0
	    
	    // start DFS
	    for(int i=0; i<V; i++)
	    {
	        if(color[i]==-1)
	        {
	            if(checkBipartiteDFS(adj,i,color,1)==false)
	            {
	                return false;
	            }
	        }
	    }
	    
	    // agar false return nahi hua kahi bhi then sab rules ke acc hai so return true;
	    return true;
	}

};