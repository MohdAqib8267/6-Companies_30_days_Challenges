class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int cnt=1;
        int res;
        while(k!=0){
            if(mp.find(cnt)!=mp.end()){
                cnt++;
            }
            else{
                res=cnt;
                cnt++;
                k--;
            }
            
        }
        return res;
    }
};