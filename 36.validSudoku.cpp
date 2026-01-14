/*
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> mp;

        //each row
        for(int i = 0; i < 9; i++){
            mp.clear();
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                mp[board[i][j]]++;
                if(mp[board[i][j]] >= 2) return false;
            }
        }

        //each column
        for(int j = 0; j < 9; j++){
            mp.clear();
            for(int i = 0; i < 9; i++){
                if(board[i][j] == '.') continue;
                mp[board[i][j]]++;
                if(mp[board[i][j]] >= 2) return false;              
            }
        }


        //3x3 box
        for(int boxRow = 0; boxRow < 3; boxRow++){
            for(int boxCol = 0; boxCol < 3; boxCol++){
                mp.clear();
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        int r = boxRow * 3 + i;
                        int c = boxCol * 3 + j;
                        if(board[r][c] == '.') continue;
                        mp[board[r][c]]++;
                        if(mp[board[r][c]] >= 2) return false;   
                    }
                }
            }
        }

        return true;
    }
};