class Solution {
public:
    int longestSubarray(vector<int>& nums)
    {
        int prev_count = -1;
        int curr_count = 0; 
        int max_count = 0; 
        
        for (int num : nums)
        {
            if (num == 1)
            {
                ++curr_count;
                if (max_count < prev_count + curr_count)
                    max_count = prev_count + curr_count;
            }
            else 
            {
                prev_count = curr_count;
                curr_count = 0;
                if (max_count < prev_count + curr_count)
                    max_count = prev_count + curr_count;
            }
        }
        return max_count;
    }
};
