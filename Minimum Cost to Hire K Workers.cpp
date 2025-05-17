class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    int n = quality.size();
    vector<pair<double, int>> ratios(n); // {wage-to-quality ratio, quality}

    // Fill the ratios vector
    for (int i = 0; i < n; i++) {
        double ratio = (double)wage[i] / quality[i];
        ratios[i] = {ratio, quality[i]};
    }

    // Sort based on the ratio
    sort(ratios.begin(), ratios.end());

    double ans = DBL_MAX;
    int totalQuality = 0;
    priority_queue<int> maxHeap;

    // First k workers (smallest ratios)
    for (int i = 0; i < k; i++) {
        totalQuality += ratios[i].second;
        maxHeap.push(ratios[i].second);
    }

    // Calculate initial cost
    ans = totalQuality * ratios[k - 1].first;

    // Try replacing max quality worker with next ones (who have higher ratio)
    for (int i = k; i < n; i++) {
        totalQuality += ratios[i].second;
        maxHeap.push(ratios[i].second);
        totalQuality -= maxHeap.top();
        maxHeap.pop();

        ans = min(ans, totalQuality * ratios[i].first);
    }

    return ans;
}
};
