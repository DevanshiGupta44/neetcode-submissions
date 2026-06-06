class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> row;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')
                {
                continue;
                }
                if(row.find(board[i][j]) != row.end())
                {
                return false;
                }
                else
                {
                    row.insert(board[i][j]);
                }
            }
        }
        for(int j=0;j<9;j++){
            unordered_set<char> col;
            for(int i=0;i<9;i++){
                if(board[i][j] == '.')
                {
                continue;
                }
                if(col.find(board[i][j]) != col.end())
                {
                return false;
                }
                else
                {
                    col.insert(board[i][j]);
                }
            }
        }
        for(int boxRow = 0; boxRow < 3; boxRow++){

    for(int boxCol = 0; boxCol < 3; boxCol++){

        unordered_set<char> box;

        int startRow = boxRow * 3;
        int startCol = boxCol * 3;

        for(int r = startRow; r < startRow + 3; r++){

            for(int c = startCol; c < startCol + 3; c++){

                if(board[r][c] == '.')
                    continue;

                if(box.find(board[r][c]) != box.end())
                    return false;

                box.insert(board[r][c]);
            }
        }
    }
}
        return true;
    }
};
