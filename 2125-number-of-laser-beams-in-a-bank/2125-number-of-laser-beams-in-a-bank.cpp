class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int i=0;
      
        int ans=0;
        while(i<n){
            
           
            int cnt1=0;
            while(cnt1==0 and i<n){
                for(int k=0;k<bank[i].size();k++){
                    if(bank[i][k]=='1'){
                        cnt1++;
                    }
                }
                if(cnt1==0){
                   i++; 
                } 
            }
            int cnt2=0;
            int j=i+1;
            while(cnt2==0 and j<n){
                 for(int k=0;k<bank[j].size();k++){
                    if(bank[j][k]=='1'){
                        cnt2++;
                    }
                }
                if(cnt2==0){
                    j++;
                }  
            }
            ans=ans+cnt1*cnt2;
            i=j;
        }
        return ans;
    }
};