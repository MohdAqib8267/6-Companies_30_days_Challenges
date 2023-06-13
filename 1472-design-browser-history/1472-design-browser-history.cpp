class BrowserHistory {
public:
    stack<string>fd,bd;
    BrowserHistory(string homepage) {
        fd.push(homepage);
    }
    
    void visit(string url) {
        fd.push(url);
        while(!bd.empty()){
            bd.pop();
        }
        return;
    }
    
    string back(int steps) {
        while(fd.size()>1 and steps--){
            bd.push(fd.top());
            fd.pop();
        }
        
        return fd.top();
    }
    
    string forward(int steps) {
        while(!bd.empty() and steps--){
            fd.push(bd.top());
            bd.pop();
        }
        return fd.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */