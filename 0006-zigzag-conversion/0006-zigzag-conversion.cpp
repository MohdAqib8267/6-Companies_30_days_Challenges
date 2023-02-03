class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>>mat(numRows);
        int g=0;
        int i=0;
        int flag=1;
        int n=s.size();
        string ans="";
        if(n==1 || numRows==1)
        return s;
        while(i<n){
            if(flag==1){
                while(i<n and g<numRows){
                    mat[g++].push_back(s[i]);
                    i++;
                }
                flag=0;
            }
            else{
                int k=numRows-2;
                while(k>=0 and i<n){
                    mat[k--].push_back(s[i]);
                    i++;
                }
                flag=1;
                g=1;
            }
        }
        for(auto it:mat){
            for(auto jt:it){
                ans+=jt;
            }
        }
        return ans;
    }
};