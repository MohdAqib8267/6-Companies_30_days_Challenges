class SnapshotArray {
public:
    map<int,map<int,int>>mp;
    int count=0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        mp[index][count]=val;
    }
    
    int snap() {
        count++;
        return count-1;
    }
    
    int get(int index, int snap_id) {
        int v = 0;

for (const auto& entry : mp[index]) {
    if (entry.first > snap_id) {
        break;
    }
    v = entry.second;
}

return v;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */