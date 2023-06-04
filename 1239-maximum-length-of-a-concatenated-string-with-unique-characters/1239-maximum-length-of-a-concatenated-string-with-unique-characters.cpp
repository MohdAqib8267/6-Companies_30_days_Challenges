class Solution {
public:
   int ans=0;
    unordered_map<char,int>mp;
    void solve(int st,vector<string>& arr){
        int res=0;
        for(auto it:mp){
            if(it.second>1) return;
            
            if(it.second==1) res++;
        }
        ans=max(ans,res);
        for(int i=st;i<arr.size();i++){
            for(auto it:arr[i]){
                mp[it]++;
            }
            solve(i+1,arr);
            for(auto it:arr[i]){
                mp[it]--;
            }
        }
    }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        solve(0,arr);
        return ans;
    }
};