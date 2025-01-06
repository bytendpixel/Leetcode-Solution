
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &ins)
    {
        ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
        int mine = ins[0][0], maxe = ins[0][1];
        for (auto &i : ins)
        {
            mine = min(i[0], mine);
            maxe = max(i[1], maxe);
        }
        for (auto &i : ins)
        {
            i[0] -= mine;
            i[1] -= mine;
        }
        //(maxe - mine + 1) is the max number of non-overlapping intervals
        vector<int> st(maxe - mine + 1, -1);
        for (auto &i : ins)
        {
            st[i[1]] = max(st[i[1]], i[0]);
        }

        int prev = -1;
        int ma = 0;
        for (int i = 0; i < st.size(); i++)
        {
            if (st[i] == -1)
                continue;
            if (st[i] > prev)
            {
                prev = i - 1;
                ma++;
            }
        }
        return (int)ins.size() - ma;
    }
};
