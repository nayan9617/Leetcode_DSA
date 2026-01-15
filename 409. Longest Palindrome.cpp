/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7. */

class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        bool oddExists = false;
        unordered_map<char, int> mp;

        for(char c : s){
            mp[c]++;
        }
        for (const auto& pair : mp) {
            char c = pair.first;
            int freq = pair.second;
            if(freq % 2 == 0) ans += freq;
            else{
                oddExists = true;
                ans += freq-1;
            }
        }

        return oddExists ? ans + 1 : ans;
    }
};