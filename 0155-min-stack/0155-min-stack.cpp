class MinStack {
public:
    stack<pair<int,int>> st;
    int min;
    MinStack(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
    }
    
    void push(int value) {
        if(st.empty()){
            min = value;
        }
        if(value < min){
            min = value;
        }
        st.push({value,min});
    }
    void pop() {
        int x = st.top().first;
        int y = st.top().second;
        st.pop();
        if(!st.empty() && x == y){
            min = st.top().second;
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */