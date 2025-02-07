class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int end = 0;
        int remain = 0;
        while (true) {
            if (remain < 0 || remain + gas[end] - cost[end] < 0) {
                start = (start - 1 + gas.size()) % gas.size();
                remain = remain + gas[start] - cost[start];
                if (remain >= 0 && start == end) return start;
            } else {
                remain = remain + gas[end] - cost[end];
                end = (end + 1) % gas.size();
                if (end == start) return start;
                continue;
            }

            if (start == 0) {
                break;
            }
        }
        return -1;
    }
};
