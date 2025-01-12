/**
 * Given an integer array nums, return all the triplets where sum=0
 *      The solution set must not contain duplicate triplets
 *      Time is 15ms :(
 **/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if( all_of(nums.begin(),nums.end(),[&](const int i) {return i == 0;}) ) return {{0,0,0}};
        int min = *min_element(nums.begin(), nums.end()), 
            max = *max_element(nums.begin(), nums.end()), 
            target;
        if (min >= 0 || max <= 0) return {};
        int range = max - min + 1, 
            exist = 0;

        vector<int> count(range, 0);
        for(int& i : nums) ++count[i - min];

        for(int i = 0; i < range; i++){
            if(count[i] !=0) nums[exist++] = i + min;
        }

        vector<vector<int>> triples;
        auto l = nums.begin(), 
             r = next(l, exist - 1);
        while(*l <=0){
            while(*r >= 0){
                target = -(*l + *r);
                if(target < *l) {
                    --r;
                    continue;
                }
                if(target > *r) break;
                if(   ( (*l == target || *r == target) && count[target - min] == 1 ) 
                   || ( (*l == target && *r == target) && count[target - min] == 2 ) 
                ){
                    --r;
                    continue;
                }
                if (count[target - min] !=0 ) triples.push_back( {*l, target, *r} );
                r--;
            }
            ++l;
            r = next(nums.begin(), exist - 1);
        }
        return triples;
    }
};
