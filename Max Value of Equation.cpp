class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // max {y_i + y_j + x_j - x_i}
        // max{x_j + y_j - x_i + y_i} for all x_j - x_i <= k
        int ret = INT_MIN;
        // {-x_i + y_i, x_i}
        priority_queue<pair<int, int>> maxHeap;
        for(const auto& point : points){
            int x_j = point[0], y_j = point[1];
            // remove the infeasible points in heap
            while(!maxHeap.empty() && x_j - maxHeap.top().second > k){
                maxHeap.pop();
            }
            if(!maxHeap.empty()){
                ret = max(ret, x_j + y_j + maxHeap.top().first);
            }
            maxHeap.push({-x_j + y_j, x_j});
        }
        return ret;
    }
};
