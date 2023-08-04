class MedianFinder {
public:
    priority_queue<int,vector<int>>mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.size()==0 || mx.top()>num){
            mx.push(num);
        }
        else{
            mn.push(num);
        }
        if(mx.size()>1+mn.size()){
            mn.push(mx.top());
            mx.pop();
        }
        else if(mn.size()>1+mx.size()){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size()==mn.size()){
            return (double) (mn.top()+mx.top())/2.0;
        }
        else if(mx.size()>mn.size()){
            return (double) mx.top();
        }
        else{
            return (double) mn.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */