class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>pairs;
        int n=spells.size(), m=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            //insted of this use binary search bcz we find a index
            int l=0;
            int h=m-1;
            int cnt=0;
            while(l<=h){
                long long mid = l+(h-l)/2;
                if((long long)spells[i]*(long long)potions[mid]>=success){
                    // cnt+=h-mid+1; //both correct
                    cnt=m-mid;
                    
                    h=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            pairs.push_back(cnt);
        }
        return pairs;
    }
};