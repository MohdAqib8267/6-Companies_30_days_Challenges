class Solution {
public:
    vector<int> countBits(int n) {
          vector <int> ans;
        ans.push_back(0);
        if(n==0){
            return ans;
        }
        ans.push_back(1);
        if(n==1){
             return ans;
        }
        
            for(int i=2;i<=n;i++){
                if(i%2==0){
                    //even number doesn't brings new 1
                    ans.push_back(ans[i/2]);
                }
                else{
                    //odd number the units place flips to 1, adding 1;
                    ans.push_back(ans[i/2]+1);
                }
            }
        
        return ans;
    }
};