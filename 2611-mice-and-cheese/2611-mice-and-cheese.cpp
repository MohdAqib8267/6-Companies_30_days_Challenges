class Solution {
public:

    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
               int n = reward1.size();
        vector<pair<int,int>> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = make_pair(reward1[i] - reward2[i], i);
        }
        // sort(diff.begin(), diff.end(), [](const auto& a, const auto& b) {
        //     return a.first > b.first;
        // });//decreasing order
        // for(int i=0;i<n;i++){
        //     cout<<diff[i].first<<" "<<diff[i].second<<endl;
        // }
        sort(diff.begin(),diff.end(),greater<pair<int,int>>());
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += reward1[ diff[i].second];
        }
        for (int i = k; i < n; i++) {
            ans += reward2[diff[i].second];
        }
        return ans;

    }
};