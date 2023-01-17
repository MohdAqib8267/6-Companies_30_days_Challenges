class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        //without DP
        int count_zero=0;
        int count_flip=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                count_zero++;
            }
            else{
                count_flip++;
            }
            count_zero=min(count_zero,count_flip);
        }
        return count_zero;
    }
};