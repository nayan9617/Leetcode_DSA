/*Reverse bits of a given 32 bits signed integer.


Example 1:
Input: n = 43261596
Output: 964176192*/

class Solution {
public:
   uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for(int i = 0; i < 32; i++){
            ans <<= 1;          // shift result to left
            ans =  ans | (n & 1);     // add last bit of n
            n >>= 1;            // move to next bit
        }

        return ans;
    }
};