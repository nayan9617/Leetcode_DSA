/*Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums1.size(); int m = nums2.size();
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            if(st.count(nums1[i])) continue;
            st.insert(nums1[i]);
        }
        for(int i = 0; i < m; i++){
            if(st.count(nums2[i])){
                ans.push_back(nums2[i]);
                st.erase(nums2[i]);
            }
        }
        return ans;
    }
};