class Solution {
public:
    int val(char c){
        if(c=='I') return 1;
        if(c=='V') return 5;
        if(c=='X') return 10;
        if(c=='L') return 50;
        if(c=='C') return 100;
        if(c=='D') return 500;
        if(c=='M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int n=s.size();
       
        int ans=0;
        for(int i=0;i<n;i++){
            if(i<n-1 and val(s[i+1])>val(s[i])){
                ans=ans+val(s[i+1])-val(s[i]);
                i++;
            }
            else{
                ans=ans+val(s[i]);
            }
        }
        return ans;
    }
};