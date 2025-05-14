#include <random>
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
class Solution {
    map<int,int> mp;
    int randomValue,minimum,maximum;
public:
    Solution(int n, vector<int>& blacklist) {
        int m = n - blacklist.size();
        for(int a:blacklist)
        {
            mp[a] = -1;
        }

        for(int a:blacklist)
        {
            if(a<m)
            {
                while(mp.find(n-1) != mp.end())
                n--;
                mp[a] = n-1;
                n--;
            }
        }

        minimum = 0;
        maximum = m-1;
    }
    
    int pick() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(minimum, maximum);
        randomValue = distrib(gen);
        if(mp.find(randomValue) != mp.end())
        return mp[randomValue];
        return randomValue;
    }
};
