class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int count=INT_MAX;;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            
            if(mp.find(cards[i])!=mp.end()){
                int no_of_cards=i-mp[cards[i]]+1;
                if(count>no_of_cards){
                    count=no_of_cards;
                }
            }
            mp[cards[i]]=i;
        }
        return count==INT_MAX?-1:count;
    }
};