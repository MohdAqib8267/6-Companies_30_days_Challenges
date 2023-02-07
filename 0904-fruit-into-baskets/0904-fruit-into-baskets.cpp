class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //sliding window maximum at most 2 distinct char
        int i=0;
        int j=0;
        int n=fruits.size();
        int ans=0;
        int cnt=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[fruits[j]]++;
            if(mp[fruits[j]]==1){
                cnt++;
            }
            
            while(cnt>2 and i<=j){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    cnt--;
                }
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};