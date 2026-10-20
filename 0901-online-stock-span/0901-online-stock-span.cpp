class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<int> st;
    vector<int> stock;
    int idx = -1;
    int next(int price) {
        stock.push_back(price);
        idx++;
        while(!st.empty() && stock[st.top()]<= price){
            st.pop();
        }
        int x = -1;
        if(!st.empty()){
            x = st.top();
        }
        st.push(idx);
        return (idx - x);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */