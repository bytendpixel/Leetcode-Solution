#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int m, n;
    const int MOD = 1e9 + 7;
    vector<vector<int>> directions = {{-1, 0}, {0, -1}}; // Only check left & up
    int dp[5][5][243][7][7]; // DP cache: [row][col][prev_mask][I][E]

    // Precompute power of 3 (since each cell has 3 states: 0,1,2)
    int pow3[6] = {1, 3, 9, 27, 81, 243}; 

    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof(dp)); 
        return dfs(0, 0, 0, introvertsCount, extrovertsCount);
    }

    int dfs(int row, int col, int prev_mask, int I, int E) {
        if (row == m) return 0; // Finished grid

        // Move to the next row
        if (col == n) return dfs(row + 1, 0, prev_mask, I, E);

        if (dp[row][col][prev_mask][I][E] != -1) return dp[row][col][prev_mask][I][E];

        int next_col = col + 1; // Move right

        // Extract left and up cell values (0 = empty, 1 = I, 2 = E)
        int left = (col > 0) ? (prev_mask % 3) : 0;
        int up = (prev_mask / pow3[n - 1]);

        // Remove left-most column and shift mask for next state
        int next_mask = (prev_mask % pow3[n - 1]) * 3;

        int maxHappiness = dfs(row, next_col, next_mask, I, E); // Case 1: Empty cell

        // Case 2: Place an introvert
        if (I > 0) {
            int happiness = 120;
            if (left) happiness -= 30, happiness += (left == 2 ? 20 : -30);
            if (up) happiness -= 30, happiness += (up == 2 ? 20 : -30);
            maxHappiness = max(maxHappiness, happiness + dfs(row, next_col, next_mask + 1, I - 1, E));
        }

        // Case 3: Place an extrovert
        if (E > 0) {
            int happiness = 40;
            if (left) happiness += 20, happiness += (left == 2 ? 20 : -30);
            if (up) happiness += 20, happiness += (up == 2 ? 20 : -30);
            maxHappiness = max(maxHappiness, happiness + dfs(row, next_col, next_mask + 2, I, E - 1));
        }

        return dp[row][col][prev_mask][I][E] = maxHappiness;
    }
};
