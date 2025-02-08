class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            std::vector<int> queens = { i };
            ans += countValid(queens, 1, n);
        }

        return ans;
    }

    bool conflict(std::vector<int> &queens, int x, int y) {
        for (int qy = 0; qy < queens.size(); ++qy) {
            int qx = queens[qy];
            if (x == qx)
                return true;
            if (y - qy == x - qx)
                return true;
            if (y - qy == qx - x)
                return true;
        }
        return false;
    }

    int countValid(std::vector<int> &queens, int y, int n) {
        int ans = 0;
        if (y >= n)
            return 1;
        for (int x = 0; x < n; ++x) {
            if (conflict(queens, x, y))
                continue;
            // try this answer;
            queens.push_back(x);
            ans += countValid(queens, y + 1, n);
            queens.pop_back();
        }
        return ans;
    }
};
