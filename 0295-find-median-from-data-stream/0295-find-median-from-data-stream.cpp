class MedianFinder {
public:
    priority_queue<int,vector<int>>pq_max;
    priority_queue<int,vector<int>,greater<int>>pq_min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq_max.size()==0 || pq_max.top()>num){
            pq_max.push(num);
        }
        else{
            pq_min.push(num);
        }
        
        if(pq_max.size()>1+pq_min.size()){
            pq_min.push(pq_max.top());
            pq_max.pop();
        }else if(pq_min.size()>1+pq_max.size()){
            pq_max.push(pq_min.top());
            pq_min.pop();
        }
    }
    
    double findMedian() {
        if(pq_max.size()==pq_min.size()){
            return (double) (pq_max.top()+pq_min.top())/2.0;
        }
        else if(pq_min.size()>pq_max.size()){
            return (double) pq_min.top();
        }
        else{
            return (double) pq_max.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */