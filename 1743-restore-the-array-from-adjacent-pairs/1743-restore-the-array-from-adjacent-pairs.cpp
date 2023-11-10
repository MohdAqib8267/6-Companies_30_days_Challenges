class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<ap.size();i++){
            mp[ap[i][0]].push_back(ap[i][1]);
            mp[ap[i][1]].push_back(ap[i][0]);
        }

        vector<int> ans;
        int n = mp.size();
        int start;

        for(auto m:mp){
            if(m.second.size() == 1){
                start = m.first;
            }
        }

        ans.push_back(start);
        ans.push_back(mp[start][0]);

        while(ans.size() != n){
            int last = ans[ans.size()-1];
            int seclast = ans[ans.size()-2];
            if(mp[last][0] != seclast){
                ans.push_back(mp[last][0]);
            }else{
                ans.push_back(mp[last][1]);
            }
        }

        return ans;
    }
};