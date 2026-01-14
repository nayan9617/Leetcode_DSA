/*Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_set<int> col;
        unordered_set<int> row;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    if(!row.count(i)){
                        row.insert(i);
                    }
                    if(!col.count(j)){
                        col.insert(j);
                    }                   
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(row.count(i) || col.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};