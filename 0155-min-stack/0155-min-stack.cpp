class MinStack {
public:
    stack<int>st,mst;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mst.empty()){
            mst.push(val);
        }else if(mst.top()>=val){
            mst.push(val);
        }
    }
    
    void pop() {
       int t=st.top();
        if(t==mst.top()){
            mst.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mst.top();
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