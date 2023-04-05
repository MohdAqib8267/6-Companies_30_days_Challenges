class Solution {
public:
    int minimizeArrayValue(vector<int>& a) {
          long long ans = 0, sum =0;
        for(int i=0;i<a.size();i++){
            sum += a[i];
            ans = max((sum+i)/(i+1), ans);
        }
        
        return ans;
    }
};