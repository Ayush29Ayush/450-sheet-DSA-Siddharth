//! Approach1 => Incomplete
// class Solution {
// private:
//     double dist(const vector<int> &arr) {
//         int sq = arr[0]*arr[0] + arr[1]*arr[1];
//         return sqrt(sq);
//     }
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//         int n = points.size();
//         if(k==n) return points;
//         vector<vector<int>> res;
//         map<double,vector<int>> mp;
        
//         for(int i=0; i<n; i++)
//         {
//             double d = dist(points[i]);
//             mp[d] = points[i];
//         }
        
//         int count=0;
//         for(int )
//     }
// };

//! Approach2 => Since K Closest likha hai so we will use heap
//! Using MIN-HEAP
// TC=>O(N) and SC=>O(N)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
		//min priority queue syntax
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        vector<vector<int>> answer;
        
        for (int i = 0; i < points.size(); i++) {
            pq.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        }
        
        while (K!=0) {
            answer.push_back(points[pq.top().second]);
            pq.pop();
            K--;
        }
        
        return answer;
    }
};

//! Approach3 => https://www.youtube.com/watch?v=z-NbVpzA_fs
// Using MAX-HEAP
// class Solution {
// public:
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
//     }
// };
