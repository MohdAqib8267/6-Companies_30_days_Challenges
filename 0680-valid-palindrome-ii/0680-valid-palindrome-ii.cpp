class Solution {
public:
    bool solve(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<j){
            if(s[i] != s[j]){
                break;
            }
            i++;
            j--;
        }
        return solve(i+1,j,s) or solve(i,j-1,s); 
        //assume delete ith element and check again next element similarly assume jth element is deleted and check further from j-1 element
        // if one the give true that,s mean a solution is possible
    }
};