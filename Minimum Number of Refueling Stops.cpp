class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(startFuel>=target)return 0;
        priority_queue<int,vector<int>,less<>>best_list;//max heap 
	    int i=0,ans=0;
        while(startFuel<target){
            while(i<stations.size() && stations[i][0]<=startFuel){
               best_list.push(stations[i][1]);
		        ++i;
            }
	        if(best_list.empty())return -1;
                startFuel+=best_list.top();
                best_list.pop();
                ++ans;
                if(startFuel>=target)return ans;
            }
        return -1;
    }
};
