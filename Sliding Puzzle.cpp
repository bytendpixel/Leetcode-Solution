#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
    const string goal = "123450";
    // zero-tile neighbors
    vector<vector<int>> nbr = {
        {1,3}, {0,2,4}, {1,5},
        {0,4}, {1,3,5}, {2,4}
    };
    // index → (row, col)
    vector<pair<int,int>> pos = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2}};
    // goal index for tile '1'…'5'
    int goalIdx[6];

    // compute sum of Manhattan distances
    int heuristic(const string &s) {
        int h = 0;
        for (int i = 0; i < 6; i++) {
            char c = s[i];
            if (c != '0') {
                int v = c - '0';
                int gi = goalIdx[v];
                h += abs(pos[i].first  - pos[gi].first)
                   + abs(pos[i].second - pos[gi].second);
            }
        }
        return h;
    }

    // IDA* DFS; returns:
    //  - if found: -1
    //  - otherwise: the minimum f = g+h that exceeded the bound
    int dfs(string &state, int zeroPos, int g, int bound, int h, int prevZero) {
        int f = g + h;
        if (f > bound) return f;
        if (state == goal) return -1;               
        int minExceed = INT_MAX;

        for (int nxt : nbr[zeroPos]) {
            if (nxt == prevZero) continue;           // don't undo
            char tile = state[nxt];
            // update h incrementally: tile moves from nxt→zeroPos
            int before = abs(pos[nxt].first  - pos[goalIdx[tile-'0']].first)
                       + abs(pos[nxt].second - pos[goalIdx[tile-'0']].second);
            int after  = abs(pos[zeroPos].first  - pos[goalIdx[tile-'0']].first)
                       + abs(pos[zeroPos].second - pos[goalIdx[tile-'0']].second);
            int h2 = h - before + after;

            // swap zero and tile
            swap(state[zeroPos], state[nxt]);
            int t = dfs(state, nxt, g+1, bound, h2, zeroPos);
            // swap back
            swap(state[zeroPos], state[nxt]);

            if (t == -1) 
                return -1;           // solution found
            minExceed = min(minExceed, t);
        }
        return minExceed;
    }

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // flatten
        string start;
        for (auto &row : board)
            for (int x : row)
                start.push_back(char('0' + x));

        // inversion count to check solvability
        int inv = 0;
        for (int i = 0; i < 6; i++) if (start[i]!='0')
            for (int j = i+1; j < 6; j++) if (start[j]!='0')
                if (start[i] > start[j]) inv++;
        if (inv & 1) return -1;

        // prepare goalIdx
        // goal = "123450", so tile v at index goalIdx[v]
        for (int i = 0; i < 6; i++)
            goalIdx[ goal[i]-'0' ] = i;

        int zpos = start.find('0');
        int h0 = heuristic(start);
        int bound = h0;

        while (true) {
            int t = dfs(start, zpos, 0, bound, h0, -1);
            if (t == -1) 
                return bound;    // found at this depth
            if (t == INT_MAX) 
                return -1;       // no solution
            bound = t;           // increase bound
        }
    }
};
