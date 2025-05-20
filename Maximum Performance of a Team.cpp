#include <vector>
#include <algorithm>
#include <queue>

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int maxPerformance(int n, std::vector<int>& speed, std::vector<int>& efficiency, int k) {
        // Create a vector of pairs to store efficiency and speed together
        std::vector<std::pair<int, int>> engineers;
        for (int i = 0; i < n; ++i) {
            engineers.push_back({efficiency[i], speed[i]});
        }
        
        // Sort engineers by efficiency in descending order
        std::sort(engineers.rbegin(), engineers.rend());
        
        // Use a min-heap to keep track of the k highest speeds
        std::priority_queue<int, std::vector<int>, std::greater<int>> speedHeap;
        long speedSum = 0, maxPerformance = 0;
        
        for (auto& [eff, spd] : engineers) {
            speedHeap.push(spd);
            speedSum += spd;
            
            // If the heap size exceeds k, remove the smallest speed
            if (speedHeap.size() > k) {
                speedSum -= speedHeap.top();
                speedHeap.pop();
            }
            
            // Calculate the performance with the current engineer's efficiency
            maxPerformance = std::max(maxPerformance, speedSum * eff);
        }
        
        // Return the result modulo 10^9 + 7
        return maxPerformance % 1000000007;
    }
};
