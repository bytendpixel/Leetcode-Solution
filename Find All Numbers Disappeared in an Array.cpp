class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while(i < n){
            int correctIndex = nums[i] - 1;
            if (nums[i] != nums[correctIndex]){
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }
                vector<int> result;
                for(int i = 0; i < n; i++){
                    if (nums[i] != i + 1){
                        result.push_back(i + 1);
                    }
                }
                return result;
        
    }
};
