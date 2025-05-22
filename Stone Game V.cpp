class Solution {
public:
    int memo[501][501];
    vector<int> prefixSum;
    
    int stoneGameV(vector<int>& stoneValue, int start, int end) {
        int score = 0;
        if(end-start <= 1) return score;
        
        if(memo[start][end] != -1){
            return memo[start][end];
        }
        
        int leftsum, rightsum;

        //left part: [start...i], right part: [i+1...end)
        for(int i = start; i < end; ++i){
            //[start...i]
            //prefixSum[i+1]: [0...i]
            //prefixSum[start]: [0...start-1]
            leftsum = prefixSum[i+1] - prefixSum[start];
            //[i+1...end)
            //prefixSum[end]: [0...end)
            //prefixSum[i+1]: [0...i]
            rightsum = prefixSum[end] - prefixSum[i+1];
            
            if(leftsum > rightsum){
                //discard left
                //remain [pos+1...]
                // cout << "add " << sum-leftsum << endl;
                score = max(score, rightsum + stoneGameV(stoneValue, i+1, end));
            }else if(leftsum < rightsum){
                //discard right
                //remain [0...pos]
                // cout << "add " << leftsum << endl;
                score = max(score, leftsum + stoneGameV(stoneValue, start, i+1));
            }else{
                //leftsum == rightsum
                int leftres = stoneGameV(stoneValue, start, i+1);
                int rightres = stoneGameV(stoneValue, i+1, end);
                // cout << "add " << leftsum << endl;
                score = max(score, leftsum + max(leftres, rightres));
            }
        }
        
        return memo[start][end] = score;
    } 
    
    int stoneGameV(vector<int>& stoneValue) {
        memset(&memo[0][0], -1, sizeof(memo));
        
        int n = stoneValue.size();
        prefixSum = vector<int>(n+1, 0);
        for(int i = 0; i < n; ++i){
            prefixSum[i+1] = prefixSum[i] + stoneValue[i];
        }
        
        return stoneGameV(stoneValue, 0, n);
    }
};
