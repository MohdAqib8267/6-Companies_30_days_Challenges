class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),cmp);
        int i=0;int j=1;
        int cnt=1;
        while(j<n){
            if(pairs[i][1]<pairs[j][0]){
                cnt++;
                i=j;
            }
            j++;
        }
        return cnt;
    }
};