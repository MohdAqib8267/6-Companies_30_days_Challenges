class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n=s.size();
        int zeros=0,ones=0;
        int i=0,j=0;
        int cnt=0;
        while(j<n){
            if(s[j]=='0'){
                zeros++;
            }else{
                ones++;
            }
            
            while(zeros>k && ones>k){
                if(s[i]=='0'){
                    zeros--;
                }
                else{
                    ones--;
                }
                i++;
            }
            
                
                cnt=cnt+(j-i+1);
            
            j++;
        }
        return cnt;
    }
};