/*Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> temp;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            temp.push_back(to_string(nums[i]));
        }

        //this is the custom sort comparator with lambda function
        //  --what it does is it take 2 strings and check if a+b > b+a returns true then a come before else swap the order!
        sort(temp.begin(), temp.end(), [](string a, string b){
            return a + b > b + a;
        });

        if(temp[0]=="0") return "0";

        for(auto& s : temp){
            ans += s;
        }
        return ans;
    }
};