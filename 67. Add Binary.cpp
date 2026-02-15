/*Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        string ans = "";

        while(i >=0 || j >= 0 || carry){
            int sum = carry;

            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            ans += (sum % 2) + '0';
            carry = sum/2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};