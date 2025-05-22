class Solution {
public:
    bool isTransformable(string s, string t) {
        vector<queue<int>> pos(10);
        int n = s.size();

        // Store positions of each digit in s
        for (int i = 0; i < n; ++i) {
            pos[s[i] - '0'].push(i);
        }

        for (char c : t) {
            int digit = c - '0';

            if (pos[digit].empty()) return false;

            int index = pos[digit].front();

            // Check for blocking smaller digits
            for (int d = 0; d < digit; ++d) {
                if (!pos[d].empty() && pos[d].front() < index) {
                    return false;
                }
            }

            pos[digit].pop();
        }

        return true;
    }
};
