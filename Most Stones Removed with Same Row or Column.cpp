class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        build(n);

        for (int i = 0; i < n; i++) {
            int r = stones[i][0], c = stones[i][1];
            
            
            if (!row_first.count(r)) {
                row_first[r] = i;
            } else {
                Union(i, row_first[r]);
            }

            if (!col_first.count(c)) {
                col_first[c] = i;
            } else {
                Union(i, col_first[c]);
            }
        }

        return n - set;
    }

    unordered_map<int,int> row_first;  // <row, idx>: 'idx' of first element with 'row'
    unordered_map<int,int> col_first;  // <col, idx>: 'idx' of first element with 'col'


    #define MAXN 1001
    int father[MAXN];
    int set = 0;

    void build(int n) {
        row_first.clear();
        col_first.clear();
        set = n;
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    int find(int i) {
        if (i != father[i]) father[i] = find(father[i]);
        return father[i];
    }

    void Union(int i, int j) {
        if (find(i) != find(j)) {
            set--;
            father[find(i)] = find(j);
        }
    }
};
