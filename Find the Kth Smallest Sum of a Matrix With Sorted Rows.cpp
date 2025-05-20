using Position = pair<vector<int>::const_iterator, vector<int>::const_iterator>;


class Solution {
    // O(k * n)
    int countLowerValues(const vector<vector<int>>& mat, int row, int maxSum, int minSumm, int limit) {
        if (row >= mat.size()) {
            return 1;
        }
        int total = 0;
        minSumm -= mat[row].front();
        for (int v : mat[row]) {
            if (!(maxSum >= v + minSumm && total < limit)) {
                break;
            }
            total += countLowerValues(mat, row + 1, maxSum - v, minSumm, limit - total);
        }
        return total;
    }

public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int first = 0;
        int last = 0;
        for (const auto& row : mat) {
            first += row.front();
            last += row.back();
        }

        int count = last - first;
        int minSumm = first;
        while (first < last) {
            int step = (last - first) / 2;
            if (countLowerValues(mat, 0, first + step, minSumm, k) < k) {
                first += step + 1;
            } else {
                last = first + step;
            }
        }

        return first;
    }

    /*
    O (n * m * k * log k)
    int kthSmallest(vector<vector<int>>& mat, int k) {
        multiset<int> counts { 0 };
        for (const auto& row : mat) {
            multiset<int> variants;
            for (int c : counts) {
                for (int v : row) {
                    variants.emplace(c + v);
                }
            }
            while (variants.size() > k) {
                variants.erase(prev(variants.end()));
            }
            swap(counts, variants);
        }
        return *prev(counts.end());
    }
    */
};
