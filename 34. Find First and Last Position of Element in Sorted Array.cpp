/*Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/

class Solution {
public:
    int findLast(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(nums[mid] <= target){
                if(nums[mid]==target){
                    ans = mid;
                }
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return ans;
    }

    int findFirst(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target){
                    ans = mid;
                }
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      if(!nums.size()) return {-1, -1};

      int first = findFirst(nums, target);
      int last = findLast(nums, target);
      return {first, last};
    }
};