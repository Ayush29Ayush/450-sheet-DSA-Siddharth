/*
    YOUTUBE VIDEO for reference :   BFS - https://www.youtube.com/watch?v=lqjlGGMjSMU
                                    DFS - https://www.youtube.com/watch?v=X1TIkW4C254
    Company Tags                : Apple, Twitter, Meta, Accolite, Amazon, Flipkart, Microsoft, Moonfrog Labs, OYO Rooms
    Leetcode Link               : https://leetcode.com/problems/course-schedule/
    GfG Link                    : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?
*/

//Approach-1 (Using BFS Cycle Check - Kahn's Algorithm (Topological Sort)
class Solution {
public:
    bool topologicalSortCheck(unordered_map<int,vector<int>> &adj, int n, vector<int> &indegree)
    {
        queue<int> que;
        int count = 0;
        
        // ab jinke degree 0 hai unko queue mein daal do
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
            {
                count++;
                que.push(i);
            }
        }
        
        while(!que.empty())
        {
            int u = que.front();
            que.pop();
            
            for(auto v : adj[u])
            {
                indegree[v]--;
                
                if(indegree[v]==0)
                {
                    count++;
                    que.push(v);
                }
            }
        }
        
        if(count == n) //I was able to visit all nodes (course)
            return true; //i.e. I was able to finish all courses
        
        return false; //means there was a cycle and I couldn't complete all courses
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>> adj;
        vector<int> indegree(numCourses,0); // Will apply Kahn's Algo now
        
        // indegree vector fill karlo elements ke degree ke saath
        for(auto vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];
            
            // pehle b then a since b is prerequisite of a.     b---->a
            adj[b].push_back(a);
            // arrow 'a' pe jaa raha
            indegree[a]++;
        }
        
        // agar cycle hua, then prerequisite wala scheme is not possible due to loop.
            // so topological sort use karke dekho since it can only be applied on D.A.G(Directed Acyclic Graph).
            // agar yppological sort nahi nikla means cycle is present so return false.
            // if cycle not present then return true.
        
        return topologicalSortCheck(adj,numCourses,indegree);
    }
};