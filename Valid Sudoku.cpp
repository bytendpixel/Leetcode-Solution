class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<std::array<bool, 9>, 9> rows{}, cols{}, squares{};

        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (!('1' <= board[i][j] && board[i][j] <= '9')) continue;
                size_t k = board[i][j] - '1';
                size_t l = i/3*3 + j/3;
                if (rows[i][k] || cols[j][k] || squares[l][k]) return false;
                rows[i][k] = cols[j][k] = squares[l][k] = true;
            }
        }
        return true;
    }
};
