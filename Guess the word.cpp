/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    // Helper function to calculate how many characters match between two strings
    // This will be used to compare the guessed word with the current word
    int numMatches(const string& s1, const string& s2) {
        int matches = 0;
        for (int index = 0; index < s1.length(); index++) {
            if (s1[index] == s2[index]) {
                matches++;  // Increment count for each matching character
            }
        }
        return matches;
    }

    // Main function to guess the secret word by interacting with the 'Master' API
    void findSecretWord(vector<string>& words, Master& master) {
        // Create a set of all possible words (initial prospects)
        unordered_set<string> prospects(words.begin(), words.end());

        // Continue guessing until we run out of prospects
        while (!prospects.empty()) {
            // Select the first word from the set as the current guess
            string frontWord = *prospects.begin();

            // Use the Master's API to get the number of matching characters with the secret word
            int numMatchesSecret = master.guess(frontWord);

            // Iterate over the set of prospective words
            for (auto it = prospects.begin(); it != prospects.end();) {
                // If the number of matches between the prospective word and the current guess 
                // is not the same as the matches with the secret word, erase it from the set
                if (numMatches(*it, frontWord) != numMatchesSecret) {
                    it = prospects.erase(it);  // Safe removal of elements during iteration
                } else {
                    ++it;  // Move to the next word in the set
                }
            }

            // Remove the current guess from the prospects set as it has been guessed
            prospects.erase(frontWord);
        }
    }
};
