/*You are given a 0-indexed integer array nums of length n.
nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.

Example 1:
Input: nums = [10,4,-8,7]
Output: 2*/

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        long long totalSum = 0;
        long long leftSum = 0;

        for(int num : nums){
           totalSum += (long long)num;
        }

        for(int i = 0; i < n-1; i++){
            leftSum += (long long)nums[i];
            if(leftSum >= (totalSum - leftSum)) count++;
        }
        return count;
    }
};