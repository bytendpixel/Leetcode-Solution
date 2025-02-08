#include <vector>
#include <algorithm>
#include <numeric>

struct Solution {
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        constexpr int MAX_PROFIT = 10000;
        int bucket[MAX_PROFIT + 1] = {0};
        int current_max = -1;

        // Early exit if all capitals are affordable
        if (int max_cap = *std::max_element(capital.begin(), capital.end()); max_cap <= w) {
            k = std::min(k, (int)profits.size());
            std::nth_element(profits.begin(), profits.begin() + k, profits.end(), std::greater<int>());
            return w + std::accumulate(profits.begin(), profits.begin() + k, 0);
        }

        // Create and sort projects by capital
        std::vector<std::pair<int, int>> projects;
        projects.reserve(profits.size());
        for (size_t i = 0; i < profits.size(); ++i) 
            projects.emplace_back(capital[i], profits[i]);
        std::sort(projects.begin(), projects.end());

        auto const* ptr = projects.data();
        auto const* end = ptr + projects.size();

        for (int remaining = k; remaining > 0; --remaining) {
            // Bulk-add eligible projects
            while (ptr < end && ptr->first <= w) {
                int p = ptr++->second;
                if (++bucket[p] == 1 && p > current_max)
                    current_max = p;
            }

            if (current_max == -1) break;

            // Apply profit and update current_max
            w += current_max;
            if (--bucket[current_max] == 0) {
                while (current_max >= 0 && bucket[current_max] == 0)
                    --current_max;
            }
        }

        return w;
    }
};
