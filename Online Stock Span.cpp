class StockSpanner {
private:
stack<pair<int,int>>st;
public:
    StockSpanner() {

    }
    int next(int price) {
        if(st.empty()){
            st.push({price,1});
            return 1;
        }
        int cnt=1;
        while(!st.empty() && st.top().first<=price){
            cnt+=st.top().second;
            st.pop();
        }
        st.push({price,cnt});
        return cnt;
    }
};

