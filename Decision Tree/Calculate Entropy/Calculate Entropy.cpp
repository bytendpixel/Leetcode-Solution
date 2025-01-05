#include <vector>
#include <unordered_map>
#include <cmath> // Required for log2

using namespace std;

class Solution {
public:
    double calculateEntropy(vector<int>& input) {
        unordered_map<int, int> frequency; // Map to store frequency of elements
        int totalElements = input.size();

        // Edge case: If the input is empty, return entropy as 0
        if (totalElements == 0) {
            return 0.0;
        }

        // Count the frequency of each value in the input
        for (int value : input) {
            frequency[value]++;
        }

        // Calculate entropy
        double entropy = 0.0;
        for (const auto& pair : frequency) {
            double probability = static_cast<double>(pair.second) / totalElements;
            entropy -= probability * log2(probability); // Use log2 for base 2 logarithm
        }

        return entropy;
    }
};
