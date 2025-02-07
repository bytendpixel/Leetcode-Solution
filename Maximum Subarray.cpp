class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = nums[0];
        int finalsum = nums[0];

        for(int i=1;i<nums.size();i++){
            if(currsum < 0){
                currsum =nums[i];
            }else{
                currsum+=nums[i];
            }
            if(finalsum<currsum){
                finalsum=currsum;
            }
        }
        return finalsum;
    }
};
