class MinStack {
public:
    /** initialize your data structure here. */
    // first element and second minimum
    deque <pair<int,int>> nums;
    
    MinStack() {
        
    }
    
    void push(int x) {
        
        if(nums.size()==0)
        {
            nums.push_back({x,x});
            return;
        }
        
        auto p = nums.back();
        int mini = min(x,p.second);
        nums.push_back({x,mini});
        
    }
    
    void pop() {
        
        if(nums.size() > 0) nums.pop_back();
    }
    
    int top() {
        
        if(nums.size() > 0) return nums.back().first;
        return -1;
    }
    
    int getMin() {
        if(nums.size() > 0) return nums.back().second;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
