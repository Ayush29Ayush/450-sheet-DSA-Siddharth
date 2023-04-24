// for reference => https://www.youtube.com/watch?v=NeU-C1PTWB8
// Approach1 => Using DFS

// class Solution {
// public:
//     bool checkBipartiteDFS(vector<vector<int>>& graph, int U, vector<int> &color, int currColor)
//     {
//         // Jis U pe aaye ho, usko color dedo
//         color[U] = currColor;
        
//          // ab DFS lagake adjecent nodes pe jao
//         for(int &v : graph[U])
//         {
//             // agar curr wale node aur adj node ka color same aaya means bipartite not possible
//             if(color[v] == color[U])
//                 return false;
            
//             // agar non visited hai toh
//             if(color[v]==-1)
//             {
//                  // dusra color likhne ka line
//                 int colorOfV = !currColor;     // yeh bhi likh sakte    int colorOfV = 1 - currColor;
//                 if(checkBipartiteDFS(graph,v,color,colorOfV)==false)
//                     return false;
//             }
//             // agar visited bhi hai v and color bhi U se same nahi hai toh last mein true return ho jayega
//         }
//         // agar false pehle kahi return nahi hua means true return hue jaa raha hai, so return true
//         return true;
//     }
    
//     bool isBipartite(vector<vector<int>>& graph) {
//         int V = graph.size();
        
//         // will also act as isVisited vector and also to denote color of nodes
//         vector<int> color(V,-1);
        
//         // Use given adj list i.e graph
        
//         // Lets take red = 1 and green = 0
        
//         // now start applying DFS
//         for(int i=0; i<V; i++)
//         {
//             if(color[i]==-1)
//             {
//                 if(checkBipartiteDFS(graph,i,color,1)==false)
// 	            {
// 	                return false;
// 	            }
//             }
//         }
//         // agar false return nahi hua kahi bhi then sab rules ke acc hai so return true;
//         return true;
//     }
// };

//Approach-2 (Graph coloring : BFS)
class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>>& adj, int curr, vector<int> &color, int currColor)
    {
        // jis node pe aa jaye usko color kardo
        color[curr] = currColor;
        
        queue<int> que;
        que.push(curr); // node ko queue mein daaldo
        
        while(!que.empty())
        {
            int U = que.front();
            que.pop();
            
            for(int &v : adj[U])
            {
                // agar curr wale node aur adj node ka color same aaya means bipartite not possible
                if(color[v]==color[U])
                    return false;
                
                // agar non visited hai toh color lagake que mein daalo
                else if(color[v]==-1)
                {
                    color[v] = 1 - color[U];
                    que.push(v);
                }
            }
            // agar visited bhi hai v and color bhi U se same nahi hai toh last mein true return ho jayega
        }
        // agar false return nahi hua kahi bhi then sab rules ke acc hai so return true;
        return true;
    }

	bool isBipartite(vector<vector<int>>& adj){
        int V = adj.size();
	    
	    vector<int> color(V, -1); //no node colored in the start
	    
	    //red = 1
	    //green = 0
	    
        // now start applying BFS
	    for(int i = 0; i<V; i++) {
	        if(color[i] == -1) {
	            if(checkBipartiteBFS(adj, i, color, 1) == false)
	                return false;
	        }
	    }
	    // agar false return nahi hua kahi bhi then sab rules ke acc hai so return true;
	    return true;
	    
	}

};
