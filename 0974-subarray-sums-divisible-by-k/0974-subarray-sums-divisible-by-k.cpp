class Solution {
public:
    //this code watch on peepcoding and code method write in DSA notebook (sliding window chapter)
    //dry-->[2,3,5,4,5,3,4]
    //agar rem -ve ho to usme +add akr dey
    //let sum=kn-rem; to krte hai
    //    sum=kn-rem+k-k
    //    sum=k(n-1)+(k-rem)  ye hum rem ko +ve bna dete hai 
    //    sum=kn'+rem ho jata hai
    
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int cnt=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(mp.find(rem)!=mp.end()){
                cnt=cnt+mp[rem];
            }
            mp[rem]++;
        }
        return cnt;
    }
};