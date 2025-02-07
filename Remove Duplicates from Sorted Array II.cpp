class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2,i = 2;
        if(nums.size() <= 2) return nums.size();
        while(i<nums.size()){
            if(nums[i] != nums[k-2]){
                nums[k] = nums[i];
                k++;
            }
            i++;
        }
        return k;
    }
};
