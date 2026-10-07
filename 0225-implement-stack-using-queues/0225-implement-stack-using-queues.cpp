class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int y = q.size();
        for(int i = 0; i < y - 1; i++){
            int z = q.front();
            q.pop();
            q.push(z);
        }
    }
    
    int pop() {
        int z = q.front();
        q.pop();
        return z;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
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