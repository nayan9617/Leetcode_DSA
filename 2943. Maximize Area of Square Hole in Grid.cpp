/*
You are given the two integers, n and m and two integer arrays, hBars and vBars. The grid has n + 2 horizontal and m + 2 vertical bars, creating 1 x 1 unit cells. The bars are indexed starting from 1.

You can remove some of the bars in hBars from horizontal bars and some of the bars in vBars from vertical bars. Note that other bars are fixed and cannot be removed.

Return an integer denoting the maximum area of a square-shaped hole in the grid, after removing some bars (possibly none).
*/

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int hIdx = hBars.size();
        int vIdx = vBars.size();

        int maxHSeq = 0;
        int maxVSeq = 0;
        pair<int, int> hseq;
        pair<int, int> vseq;

        // start and end index of longest sequence in hBars
        for(int i = 0; i < hIdx-1; i++){
            int j = i;
            while(j < hIdx-1 && hBars[j] + 1 == hBars[j+1]){
                j++;
            }
            if(j-i > maxHSeq){
                maxHSeq = j-i;
                hseq.first = i;
                hseq.second = j;
            }
            i = j;
        }

        // start and end index of longest sequence in vBars
        for(int i = 0; i < vIdx-1; i++){
            int j = i;
            while(j < vIdx-1 && vBars[j] + 1 == vBars[j+1]){
                j++;
            }
            if(j-i+1 > maxVSeq){
                maxVSeq = j-i+1;
                vseq.first = i;
                vseq.second = j;
            }
            i = j;
        }

        int maxLen = min(hseq.second - hseq.first + 2, vseq.second - vseq.first + 2);
        return maxLen * maxLen;
    }
};