class Solution {
public:
    bool isMatch(string s, string p) {
        // Initialize pointers for the string and pattern
        int i = 0, j = 0;
        // Variables to track the position of the last '*' in the pattern
        int star = -1, match = 0;
        
        // Traverse the string `s`
        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                // Case 1: Characters match or `?` matches any single character
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                // Case 2: '*' can match zero or more characters
                star = j;    // Save the position of '*'
                match = i;   // Save the current position in `s` for backtracking
                j++;         // Move to the next character in the pattern
            } else if (star >= 0) {
                // Case 3: No match, but a previous '*' allows backtracking
                j = star + 1;  // Revert `j` to the position after '*'
                i = ++match;   // Increment `match` to include the next character in `s`
            } else {
                // Case 4: No match and no previous '*', return false
                return false;
            }
        }
        
        // Ensure the remaining characters in `p` are all `*`
        while (j < p.size() && p[j] == '*') {
            j++;
        }
        
        // If we have consumed the entire pattern, return true
        return j == p.size();
    }
};
