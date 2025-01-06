class Solution {
public:
    void heapify(vector<std::pair<int,int>>& vec, int idx, int end_idx) {
        int left_idx = idx * 2 + 1;
        int right_idx = left_idx + 1;
        if (right_idx <= end_idx) {
            int target_idx = vec[left_idx].second < vec[right_idx].second ? left_idx : right_idx;
            if (vec[target_idx].second < vec[idx].second) {
                std::swap(vec[target_idx], vec[idx]);
                heapify(vec, target_idx, end_idx);
            }
        }
        else if (left_idx <= end_idx) {
            if (vec[left_idx].second < vec[idx].second) {
                std::swap(vec[left_idx], vec[idx]);
                heapify(vec, left_idx, end_idx);
            }
        }
    }

    long long totalCost(vector<int>& costs, int k, int candidates) {
        std::vector<std::pair<int,int>> heap_v;
        heap_v.reserve(candidates * 2);

        int left_idx = 0;
        int right_idx = 0;
        int last_idx = costs.size() - 1;
        for (int offset = 0; offset < candidates; ++offset) {
            left_idx = offset;
            right_idx = last_idx - left_idx;
            if (right_idx < left_idx) {
                break;
            }
            else if (right_idx == left_idx) {
                heap_v.emplace_back(left_idx, costs[left_idx]);
                break;
            }
            heap_v.emplace_back(left_idx, costs[left_idx]);
            heap_v.emplace_back(right_idx, costs[right_idx]);
        }

        last_idx = heap_v.size() - 1;
        for (int i = (heap_v.size() - heap_v.size() % 2) / 2 - 1; 0 <= i; --i) {
            heapify(heap_v, i, last_idx);
        }

        long long total = 0;
        int end_idx = heap_v.size() - 1;
        for (int i = 1; i <= k; ++i) {
            total += heap_v[0].second;
            if (heap_v.size() + i <= costs.size()) {
                if (heap_v[0].first <= left_idx) {
                    left_idx++;
                    heap_v[0] = {left_idx, costs[left_idx]};
                }
                else {
                    right_idx--;
                    heap_v[0] = {right_idx, costs[right_idx]};
                }
            }
            else {
                std::swap(heap_v[0], heap_v[end_idx]);
                end_idx--;
            }
            heapify(heap_v, 0, end_idx);
        }

        return total;
    }
};
