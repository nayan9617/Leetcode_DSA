/*You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. You are also given an integer k.

Pick the scores of any k students from the array so that the difference between the highest and the lowest of the k scores is minimized.

Return the minimum possible difference.

 

Example 1:

Input: nums = [90], k = 1
Output: 0
Explanation: There is one way to pick score(s) of one student:
- [90]. The difference between the highest and lowest score is 90 - 90 = 0.
The minimum possible difference is 0.*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i <= n-k; i++){
            int highScore = nums[i+k-1];
            int lowScore = nums[i];
            int diff = highScore - lowScore;
            ans = min(ans, diff);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};