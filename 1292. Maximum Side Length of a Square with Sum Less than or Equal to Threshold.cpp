/*
Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

Example 1:
Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
Output: 2
Explanation: The maximum side length of square with sum less than 4 is 2 as shown.*/

class Solution {
public:
    bool existsSquare(vector<vector<int>>& pref, int k, int threshold, int n, int m){
        for(int i = 0; i + k <= n; i++){
            for(int j = 0; j + k <= m; j++){
                int r1 = i, c1 = j;
                int r2 = i+k, c2 = j+k;

                int sum = pref[r2][c2] - pref[r1][c2] - pref[r2][c1] + pref[r1][c1];
                if(sum <= threshold) return true;
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));

        //prefix sum of any matrix
        for(int i = 1; i <=n; i++){
            for(int j = 1; j <= m; j++){
                pref[i][j] = mat[i-1][j-1]
                            + pref[i-1][j]
                            + pref[i][j-1]
                            - pref[i-1][j-1];
            }
        }

        int low = 0, high = min(n, m), ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(existsSquare(pref, mid, threshold, n, m)){
                ans = mid;
                low = mid+1;
            } else{
                high = mid - 1;
            }
        }
        return ans;
    }
};