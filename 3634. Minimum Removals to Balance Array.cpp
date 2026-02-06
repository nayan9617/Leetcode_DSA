/*You are given an integer array nums and an integer k.
An array is considered balanced if the value of its maximum element is at most k times the minimum element.
You may remove any number of elements from nums​​​​​​​ without making it empty.
Return the minimum number of elements to remove so that the remaining array is balanced.

Note: An array of size 1 is considered balanced as its maximum and minimum are equal, and the condition always holds true.
 
Example 1:
Input: nums = [2,1,5], k = 2
Output: 1

Explanation:
Remove nums[2] = 5 to get nums = [2, 1].
Now max = 2, min = 1 and max <= min * k as 2 <= 1 * 2. Thus, the answer is 1.*/

class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxWindow = 0;
        int l = 0;
        
        for(int r = 0; r < n; r++){
            while((long long)nums[r] > (long long)nums[l] * k){
                l++;
            }
            maxWindow = max(maxWindow, r - l + 1);
        }
    
        return n - maxWindow;
    }
};