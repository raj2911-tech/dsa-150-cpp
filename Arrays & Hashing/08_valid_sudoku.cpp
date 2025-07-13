/*
Problem: Valid Sudoku  
Link: https://leetcode.com/problems/valid-sudoku/  
Category: Hashing / Matrix  
Difficulty: Medium  

Approach:  
- Use three arrays of hash sets to keep track of seen digits:  
  1. `row[i]` for elements seen in the i-th row  
  2. `col[j]` for elements seen in the j-th column  
  3. `box[k]` for elements seen in the k-th 3x3 sub-box  
     (k = (i / 3) * 3 + (j / 3) for box index)

- For each non-empty cell (i, j), check if the digit already exists in the corresponding row, column, or box:  
  - If yes, return `false` (invalid board)  
  - If no, insert the digit into the respective sets

Time Complexity:  
- O(1) — board size is always 9x9, so operations are constant time  
- Each cell is visited once and set operations are O(1)

Space Complexity:  
- O(1) — fixed space for 27 hash sets (9 rows + 9 columns + 9 boxes)

If the board were dynamic in size (e.g. NxN), then:
    -Time: O(N²)
    -Space: O(N) per row/column/box (up to 3N sets)

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int index = (i / 3) * 3 + j / 3;  // Calculate box index

                // If element already exists in row, col or box — invalid
                if (row[i].count(board[i][j]) || 
                    col[j].count(board[i][j]) || 
                    box[index].count(board[i][j]))
                    return false;

                // Insert element into row, column and box sets
                char el = board[i][j];
                row[i].insert(el);
                col[j].insert(el);
                box[index].insert(el);
            }
        }

        return true;  // Board is valid
    }
};
