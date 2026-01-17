/*You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

 

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false
*/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int s = flowerbed.size();

        for(int i = 0; i < s && n > 0; i++){
            if(flowerbed[i]==1) continue;

            int left = (i==0) ? 0 : flowerbed[i-1];
            int right = (i==s-1) ? 0 : flowerbed[i+1];

            if(left == 0 && right == 0){
                n--;
                flowerbed[i]=1;
            }
        }
        return n==0;
    }
};