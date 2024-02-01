class MinStack {
public:
    stack<long long>st;
    long long mini;
    MinStack() {
        mini=1e10;
    }
    
    void push(int val) {
        if(val<mini){
            st.push(2*(long long)val-mini);
            mini=val;
        }
        else st.push(val);
    }
    
    void pop() {
        if(st.top()<mini) mini=2*mini-st.top(); 
        st.pop();
    }
    
    int top() {
        if(st.top()<mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */