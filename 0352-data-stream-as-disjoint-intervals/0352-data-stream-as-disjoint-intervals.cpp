class SummaryRanges {
public:
    SummaryRanges() {
        
    }
    map<int,int>mp;
    
    void addNum(int value) {
        mp[value]++;
    }
    
    vector<vector<int>> getIntervals() {
        int st=-1;
        int en=-1;
        vector<vector<int>>ans;
        for(auto it=mp.begin();it!=mp.end();it++){
            st=it->first;
            en=it->first;
            while(mp.find(en+1)!=mp.end()){
                en=en+1;
                it++;
            }
            
            ans.push_back({st,en});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */