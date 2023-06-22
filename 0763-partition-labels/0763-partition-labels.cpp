class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        //store the last index of every char
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        vector<int>ans;
        int mx=0;
        int j=0;
        for(int i=0;i<n;i++){
            //find maximum index
            mx=max(mx,mp[s[i]]);
            //if our i==mx index that's mean it is a portion where each letter in one part
            if(i==mx){
                ans.push_back(i-j+1);
                j=i+1;
            }
        }
        return ans;
    }
};