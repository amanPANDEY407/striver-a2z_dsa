class MyQueue {
public:
    stack<int> st;
    stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    int pop() {
        int x = peek();
        s.pop();
        return x;
    }
    
    int peek() {
        if(s.empty()){
            while(!st.empty()){
                s.push(st.top());
                st.pop();
            }
            return s.top();
        }
        else{
            return s.top();
        }
    }
    
    bool empty() {
        if(s.empty() && st.empty()){
            return true; 
        }else{
            return false;
        }
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