class MinStack {
public:
    stack<long> stk;
    long min;

    MinStack() {
        
    }
    
    void push(int val) {
        if (stk.empty()) {
            stk.push(0);
            min = val;
            return;
        }
        stk.push(val-min);
        if (val < min) min = val;
    }
    
    void pop() {
        if (stk.empty()) return;
        long top = stk.top();
        stk.pop();
        if (top < 0) {
            min = min - top;
        }
    }
    
    int top() {
        long top = stk.top();
        return (top > 0) ? (top + min) : (int)min;
    }
    
    int getMin() {
        return (int)min;
    }
};
