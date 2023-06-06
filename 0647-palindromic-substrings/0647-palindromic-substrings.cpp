class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,int n,string &s){
        if(i>=n){
            return 0;
        }
        int count=solve(i+1,n,s);
        for(int ind=i;ind<n;ind++){
            if(isPalindrome(i,ind,s)){
                count++;
            }
        }
        return count;
        
    }
    int countSubstrings(string s) {
        int n=s.size();
        return solve(0,n,s);
    }
};