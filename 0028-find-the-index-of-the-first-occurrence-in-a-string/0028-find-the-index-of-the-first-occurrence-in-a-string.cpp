class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.size();
        int n=haystack.size();
        int i=0,j=m-1;
        // cout<<haystack.substr(i,j+1);
        while(j<n and i<n){
            cout<<haystack.substr(i,j+1)<<endl;
            if(j-i+1==m and haystack.substr(i,m)==needle){
                return i;
            }
            i++;
            j++;
        }
        return -1;
    }
};