class Solution {
public:
    int countHomogenous(string s) {
        int n=s.size();
       char ch=s[0];
       
       vector<long long>cnts;
        int c=1;
        for(int i=1;i<n;i++){
            if(ch==s[i]){
                c++;
            }
            else{
                cnts.push_back((long long)c);
                ch=s[i];
                c=1;
            }
        }
        cnts.push_back((long long)c);
        int ans=0;
        int mod=1e9+7;
        for(int i=0;i<cnts.size();i++){
            // cout<<cnts[i]<<endl;
            ans=(ans+(cnts[i]*(cnts[i]+1)/2))%mod;
        }
        return ans;
    }
};