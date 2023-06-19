class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(strs[0]==""){
            return "";
        }
        string ans=strs[0];
        if(strs.size()>1){
            for(int i=1;i<n;i++){
                string temp=strs[i];
                int j=0;
                while(j<ans.size() and ans[j]==temp[j]){
                    j++;
                }
                ans.resize(j);
                if(j==0){
                    return "";
                }
            }
        }
        return ans;
    }
};