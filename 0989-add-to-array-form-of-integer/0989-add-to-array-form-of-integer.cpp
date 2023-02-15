class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int carry=0;
        int i=num.size()-1;
        vector<int>ans;
        while(i>=0 || k>0 || carry!=0 ){
          int sum=0;
            if(i>=0){
                sum=sum+num[i];
            }
            sum=sum+k%10;
            k=k/10;
            if(carry){
                sum=sum+carry;
            }
        
            ans.push_back(sum%10);
            carry=sum/10;
            i--;
        }
         reverse(ans.begin(),ans.end());
        return ans;
    }
};