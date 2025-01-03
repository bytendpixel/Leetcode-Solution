#pragma GCC optimize("O3", "unroll-loops")

static auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        // support variables
        int len = nums.size(), dpLen = len - k + 1, bestLen = dpLen - k, cum[dpLen],
            tot = accumulate(begin(nums), begin(nums) + k, 0);
        pair<int, int> bestLeft[bestLen];
        vector<int> res(3);
        // populating cum and bestLeft
        cum[0] = tot, bestLeft[0] = {tot, 0};
        for (int i = 0, j = k, bestTot = tot, bestI = 0; j < bestLen;) {
            // updating tot
            tot += nums[j++] - nums[i++];
            cum[i] = tot;
            if (tot > bestTot) {
                bestTot = tot;
                bestI = i;
            }
            bestLeft[i] = {bestTot, bestI};
        }
        for (int i = bestLen - k, j = bestLen; j < len;) {
            // updating tot
            tot += nums[j++] - nums[i++];
            cum[i] = tot;
        }
        // computing res
        for (int i = dpLen - 1, j = i - k, l = j - k, bestTot = 0, bestI = 0,
            currSum, bestSum = 0; l >= 0; i--, j--, l--) {
            tot = cum[i];
            if (tot >= bestTot) {
                bestTot = tot;
                bestI = i;
            }
            currSum = bestLeft[l].first + cum[j] + bestTot;
            if (currSum >= bestSum) {
                bestSum = currSum;
                res = {bestLeft[l].second, j, bestI};
            }
        }
        return res;
    }
};
