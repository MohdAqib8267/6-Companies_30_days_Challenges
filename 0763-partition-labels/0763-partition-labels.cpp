class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        int j=0;
        vector<int>ans;
        int mx=INT_MIN;
        for(int i=0;i<s.size();i++){
            mx=max(mx,mp[s[i]]);
            if(i==mx){
                ans.push_back(i-j+1);
                j=i+1;
            }
        }
        return ans;
    }
};