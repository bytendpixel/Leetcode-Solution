class Solution {
public:
    int thirdMax(vector<int>& nums) {
      sort(nums.begin(),nums.end(),greater<int>()); //decsending order sort

      int count=1;
      int max=nums[0];

      for(int i=1;i<nums.size();i++){
        if(nums[i] != max){
            max= nums[i];
            count++;
        }
        if(count == 3){
            return nums[i];
        }
      }
        return nums[0];
    }
};
