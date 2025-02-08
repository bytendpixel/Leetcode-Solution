class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool find(vector<vector<char>>& board, string& word, int i, int j,
              int idx) {
        // base case for theend of length of he substring


        if (idx == word.size()) {
            return true;
        }
        // if we are going to visit the already visited elements
        if (i < 0 || j < 0 || i >=m || j >=n || board[i][j] == '!'||board[i][j]!=word[idx]) {
            return false;
        }

        // if(board[i][j]!=word[idx])
        //     return false;

        //  storing the previous state to recove

        char ch = board[i][j];
        board[i][j] = '!';
        // performing all the combinations

        for (auto dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if (find(board, word, new_i, new_j, idx + 1)) {
                return true;
            }
        }
        board[i][j] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        m = board.size();
        n = board[0].size();
        if(word.size()>m*n) return false;
        

        unordered_map<char, int> board_freq, word_freq;
        for (auto& row : board) {
            for (char c : row) board_freq[c]++;
        }
        for (char c : word) word_freq[c]++;

        for (auto& [c, count] : word_freq) {
            if (board_freq[c] < count) return false;
        }

       // Step 2: Optimize search by sorting based on character frequency
        if (board_freq[word[0]] > board_freq[word.back()]) {
            reverse(word.begin(), word.end());
        }

        
        for (int i = 0; i <m; i++) {
            for (int j = 0; j <n; j++) {
                if (board[i][j] == word[0] && find(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
