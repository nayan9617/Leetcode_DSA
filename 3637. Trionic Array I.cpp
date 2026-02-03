/*You are given an integer array nums of length n.

An array is trionic if there exist indices 0 < p < q < n − 1 such that:

nums[0...p] is strictly increasing,
nums[p...q] is strictly decreasing,
nums[q...n − 1] is strictly increasing.
Return true if nums is trionic, otherwise return false.
Example 1:
Input: nums = [1,3,5,4,2,6]
Output: true
*/

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        int i = 0;


        while (i + 1 < n && nums[i + 1] > nums[i]) i++;
        if (i == 0) return false; 

        int j = i;
        while (j + 1 < n && nums[j + 1] < nums[j]) j++;
        if (j == i) return false; 

        int k = j;
        while (k + 1 < n && nums[k + 1] > nums[k]) k++;
        if (k == j) return false;  

        return k == n - 1;
    }
};
