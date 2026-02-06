/*You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.

Return the minimum number of moves to make every value in nums unique.

The test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].*/

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int minIncrements = 0;
        int maxElement = 0;
        for(int num : nums){
            maxElement = max(maxElement, num);
        }

        vector<int> freq(nums.size() + maxElement+1, 0);
        for(int num : nums){
            freq[num]++;
        }

        for(int i = 0; i < freq.size(); i++){
            if(freq[i] <= 1) continue;

            int duplicate = freq[i] - 1;
            freq[i+1] += duplicate;
            freq[i] = 1;
            minIncrements += duplicate;
        }
        return minIncrements;
    }
};