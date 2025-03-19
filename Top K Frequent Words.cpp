class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        struct Compare{
            bool operator()(const pair<int,string>&a,const pair<int,string>&b){
                if(a.first==b.first){
                    return a.second>b.second;
                }
                return a.first<b.first;
            }
        };
        map<string,int>mp;
        for(auto &s: words){
            mp[s]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,Compare>pq;
        for(auto &it: mp){
            pq.push({it.second,it.first});
        }
        vector<string>ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
