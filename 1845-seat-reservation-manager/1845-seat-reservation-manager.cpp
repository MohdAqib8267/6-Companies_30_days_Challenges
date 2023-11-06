class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<bool>rs;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            pq.push(i);
        }
        rs.resize(n+1,false);
    }
    
    int reserve() {
        if(rs[pq.top()]==false){
            rs[pq.top()]=true;
            
        }
        int x=pq.top();
        pq.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        if(rs[seatNumber]==true){
            rs[seatNumber]=false;
            pq.push(seatNumber);
        }
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */