class FreqStack {
public:
// Bucker sort of implementaiton
    vector<vector<int>> count;
    unordered_map<int, int> freq;
    FreqStack() {

    }
    
    void push(int val) {
        int curCount = freq[val];
        if(count.size() < curCount + 1){
            vector<int> newCount;
            count.push_back(newCount);
        }
        count[curCount++].push_back(val);
        freq[val] = curCount;
    }
    
    int pop() {
        int val = count.back().back();
        count.back().pop_back();
        if(count.back().size() == 0){
            count.pop_back();
        }
        freq[val] -= 1;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
