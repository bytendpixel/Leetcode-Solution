class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        int max_val = 0;

        for (auto& potion : potions)
            max_val = max(max_val, potion);

        int postfix[max_val + 1];

        memset(postfix, 0, sizeof(postfix));

        for (auto& potion : potions)
            postfix[potion]++;

        for (int i = max_val - 1; i >= 0; --i)
            postfix[i] += postfix[i + 1];

        for (int i = 0; i < spells.size(); ++i) {
            long long val = success / (long long)spells[i];

            if (success % (long long)spells[i] != 0)
                val++;

            spells[i] = val <= max_val ? postfix[val] : 0;
        }

        return spells;
    }
};
