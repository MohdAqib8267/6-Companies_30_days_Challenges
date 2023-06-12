class MyStack {
public:
    queue<int>q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int el=q1.front();
        q1.pop();
        swap(q1,q2);
        return el;
    }
    
    int top() {
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        int el=q1.front();
       q2.push(q1.front());
        q1.pop();
        swap(q1,q2);
        return el;
    }
    
    bool empty() {
        if(q1.empty() and q2.empty()){
            return true;
        }
        return false;
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