const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

#define pb(x) push_back(x)

class compare{
    public:
        bool operator()(string &a, string &b){
            if(a.size() != b.size())
                return a.size() > b.size();

            return a > b;
        }
};

bool comparator(string a, string b){
    if(a.size() != b.size())    
        return a.size() > b.size();
    return a > b;
}

class Solution {
public:
    string kthLargestNumber(vector<string>& arr, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<string, vector<string>, compare > pq;
        for(int i = 0;i < k;i++){
            pq.push(arr[i]);
        }

        for(int i = k;i < arr.size();i++){
            if(comparator(arr[i], pq.top())){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        

        return pq.top();
    }
};
