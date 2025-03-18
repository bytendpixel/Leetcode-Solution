class Solution {
public:

    void dfs(string src,unordered_map<string, priority_queue<string,vector<string>,greater<string>>>&graph, vector<string>&ans)
    {
        while (!graph[src].empty()) {
       
        string nextDest = graph[src].top();
        graph[src].pop();

        dfs(nextDest, graph, ans);
    }
    ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, priority_queue<string,vector<string>,greater<string>>>graph;

        for(vector<string>&ticket: tickets)
        {
            string from = ticket[0];
            string to = ticket[1];

            graph[from].push(to);
        }

        string src="JFK";

        vector<string>ans;

        dfs(src, graph, ans);
        reverse(ans.begin(), ans.end());
        return ans;


    }
};
