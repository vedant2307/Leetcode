class MyStack {
public:
    queue<int>q;
    int size;
    MyStack() {
        size=0;
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0;i<size;i++) {
            int y=q.front(); q.pop();
            q.push(y);
        }
        size++;
    }
    
    int pop() {
        int y=q.front();
        q.pop();
        size--;
        return y;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */