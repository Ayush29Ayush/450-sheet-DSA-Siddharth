// refer this if needed -> https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/discuss/1254128/C%2B%2B-Solution-with-Rotation-Working-and-Easy-Explanation
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if(mat == target) {     // rotation by 0 degree.
            return true;
        }
        
        int deg = 3;    // more rotations with 90, 180, 270 degree's.
        
        while(deg --) {
            for(int i = 0; i < n; i ++) {
                for(int j = i; j < n; j ++) {
                    swap(mat[i][j], mat[j][i]);     // transpose of matrix.
                }
            }
            for(int i = 0; i < n; i ++) {
                reverse(mat[i].begin(),mat[i].end());       // reverse each row.
            }
            if(mat == target) {
                return true;
            }
        }
        return false;
    }
};