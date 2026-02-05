/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = nums[0];
        int vote = 0;
        for(int i = 0; i < n; i++){
            if(vote == 0){
                candidate = nums[i];
                vote += 1;
            }
            else if(candidate == nums[i]){
                vote++;
            } else{
                vote--;
            }
        }
        return candidate;
    }
};