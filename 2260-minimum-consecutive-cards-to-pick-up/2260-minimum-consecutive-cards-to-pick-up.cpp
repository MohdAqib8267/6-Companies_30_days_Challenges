class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        unordered_map<int,int>mp;
        int len=INT_MAX;
        for(int i=0;i<n;i++){
            if(mp.find(cards[i])!=mp.end()){
                len=min(len,i-mp[cards[i]]+1);
            }
            mp[cards[i]]=i;
        }
        return len==INT_MAX?-1:len;
    }
};