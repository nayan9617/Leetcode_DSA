/*You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char givenTarget = target - 'a';
        int left = 0;
        int right = letters.size() - 1;
        char minAns = 'z'-'a';
        char res=letters[0];
        while(left <= right){
            int mid = left + (right-left)/2;
            if(letters[mid]-'a' > givenTarget){
                if(letters[mid]-'a' <= minAns){
                    minAns = letters[mid]-'a';
                    res=letters[mid];
                }
                right--;
            } else{
                left++;
            }
        }
        return res;
    }
};