class Solution {
public:
    // Function to calculate the total hours to eat all bananas at a given speed `k`
    long long calculateTotalHours(const vector<int>& piles, int k) {
        long long totalHours = 0;
        for (int pile : piles) {
            totalHours += (long long)(pile + k - 1) / k;  // Prevent overflow by casting to long long
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        // Binary search to find the minimum speed k
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHours = calculateTotalHours(piles, mid);

            if (totalHours <= h) {
                high = mid - 1;  // Try to find a smaller k
            } else {
                low = mid + 1;  // Increase k to eat faster
            }
        }

        // The low pointer will point to the minimum k that satisfies the condition
        return low;
    }
};
