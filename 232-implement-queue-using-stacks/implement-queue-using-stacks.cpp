class MyQueue {
public:
    stack<int>st1,st2;
    int size;
    MyQueue() {
        size=0;
    }
    
    void push(int x) {
        st1.push(x);
        size++;
    }
    
    int pop() {
        if(st2.empty()) {
            while(!st1.empty()){
                st2.push(st1.top()); st1.pop();
            }
        }
        int y=st2.top(); st2.pop();
        size--;
        return y;
    }
    
    int peek() {
        if(st2.empty()) {
            while(!st1.empty()){
                st2.push(st1.top()); st1.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return size==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */