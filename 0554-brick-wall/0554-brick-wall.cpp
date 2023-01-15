// cross+gap=size and we know size is constant. 
// So gap=size-cross
// to get minimum cross, we need to get the maximum gap

// test case => wall = [[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> mp;
        int cross=0;
        
        for(int i=0 ; i<wall.size(); i++)
        {
            int brick_end=0;
            // size-1 because last brick ko include nahi karna
            for(int j=0; j<wall[i].size()-1; j++)
            {
                brick_end += wall[i][j]; // 1,3,5 in 1st iteration, inn bricks ke end pe gap milega so include them in map
                mp[brick_end]++;
            }
        }
        
        // for this test case, 4:4 will be the maximum, so max_gap=4
        int max_gap=0;
        for(auto element : mp)
        {
            max_gap = max(max_gap, element.second);
        }
        
        cross = wall.size()-max_gap; // 6-4=2
        return cross;
    }
};