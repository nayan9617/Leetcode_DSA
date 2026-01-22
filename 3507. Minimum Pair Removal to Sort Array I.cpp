/*Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.*/

class Solution {
public:
    bool isSorted(vector<int>& nums){
        int n = nums.size();
        bool isAlreadySorted = true;
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] < nums[i]){
                isAlreadySorted = false;
            }
        }

        return isAlreadySorted;
    }

    int minimumPairRemoval(vector<int>& nums) { 
        if(isSorted(nums)) return 0;
        int count = 0;

        while(1){
            int minSum = INT_MAX;
            int adjIdx1, adjIdx2;
            for(int i = 0; i < nums.size()-1; i++){
                int sum = nums[i] + nums[i+1];
                if(sum < minSum){
                    minSum = sum;
                    adjIdx1 = i;
                    adjIdx2 = i+1;
                }
            }
            nums[adjIdx1] = minSum;
            nums.erase(nums.begin() + adjIdx2);
            count++;

            if(isSorted(nums)) break;  
        }
        return count;
    }
};