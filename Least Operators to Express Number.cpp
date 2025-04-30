class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int pos = 0, neg = 0, k, pos2, neg2, next;
        for (k = 0; target > 0; ++k, target /= x) {
            next = target % x;
            if (k > 0) {
                pos2 = min(next * k + pos, (next + 1) * k + neg);
                neg2 = min((x - next) * k + pos, (x - next - 1) * k + neg);
                pos = pos2, neg = neg2;
            } else {
                pos = next * 2;
                neg = (x - next) * 2;
            }
        }
        return min(pos, k + neg) - 1;        
    }
};
