class BrowserHistory {
public:
    stack<string>fd;
    stack<string>bc;
    BrowserHistory(string homepage) {
        fd.push(homepage);
    }
    
    void visit(string url) {
        fd.push(url);
        while(!bc.empty()){
            bc.pop();
        }
        return;
    }
    
    string back(int steps) {
        while(fd.size()>1 and steps--){
            string curr_url = fd.top();
            fd.pop();
            bc.push(curr_url);
        }
        return  fd.top();
        
    }
    
    string forward(int steps) {
        
        while(!bc.empty() and steps--){
            string url = bc.top();
            bc.pop();
            fd.push(url);
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