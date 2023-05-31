class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>checkInStation;
    unordered_map<string,pair<int,int>>checkOutStation;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInStation[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto cIn = checkInStation[id];
        string route = cIn.first+"->"+stationName;
        int timeDiff = t-cIn.second;
        checkOutStation[route].first+=timeDiff;
        checkOutStation[route].second+=1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        
         string route  = startStation + "->" + endStation;
           auto time = checkOutStation[route];

        return (double)time.first/time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */