class Solution {
public:
    bool canAssign(vector<int>& jobs, vector<int>& workloads, int idx, int limit) {
        if (idx == jobs.size()) return true;

        int currJob = jobs[idx];
        for (int i = 0; i < workloads.size(); ++i) {
            if (workloads[i] + currJob <= limit) {
                workloads[i] += currJob;
                if (canAssign(jobs, workloads, idx + 1, limit)) return true;
                workloads[i] -= currJob;
            }

            // Prune: if this worker has no job yet and couldn't take this one, others won't either
            if (workloads[i] == 0) break;
        }
        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(), jobs.rend()); // sort descending for better pruning
        int left = *max_element(jobs.begin(), jobs.end());
        int right = accumulate(jobs.begin(), jobs.end(), 0);

        while (left < right) {
            int mid = (left + right) / 2;
            vector<int> workloads(k, 0);
            if (canAssign(jobs, workloads, 0, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
