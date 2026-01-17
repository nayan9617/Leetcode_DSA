/*Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.*/

class Solution {
public:
    //function to check if a string is palindrome or not!
    bool checkPalindrome(string s, int left, int right){
        while(left <= right){
            if(s[left]!=s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left]==s[right]){
                left++;
                right--;
            } else{
                return checkPalindrome(s, left+1, right) || checkPalindrome(s, left, right-1);
            }
        }
        return true;
    }
};