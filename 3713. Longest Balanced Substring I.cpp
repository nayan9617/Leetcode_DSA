/*You are given a string s consisting of lowercase English letters.

A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

Return the length of the longest balanced substring of s.

Example 1:
Input: s = "abbac"
Output: 4
Explanation:
The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.*/

class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;
        vector<int> arr(26);

        for(int i = 0; i < n; i++){
            fill(arr.begin(), arr.end(), 0);
            for(int j = i; j < n; j++){
                bool sameFreq = true;
                int ch = s[j] - 'a';
                arr[ch]++;
                for(auto x : arr){
                    if(x > 0 && x != arr[ch]){
                        sameFreq = false;
                        break;
                    }
                }
                if(sameFreq){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};