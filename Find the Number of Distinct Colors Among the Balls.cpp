class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> answer(queries.size(), 0);
        unordered_map<int, int> map;
        unordered_map<int, int> colour;
        int oldCol,newCol;

        for (int i = 0; i < queries.size(); i++) {
            oldCol = colour[queries[i][0]];
            newCol =  queries[i][1];
            if (oldCol == 0) {
                colour[queries[i][0]] = newCol;
                map[newCol]++;
            } else {
                if (--map[oldCol] == 0)
                    map.erase(oldCol);
                map[newCol]++;
                colour[queries[i][0]] = newCol;
            }
                answer[i] = map.size();
        }
        return answer;
    }
};
