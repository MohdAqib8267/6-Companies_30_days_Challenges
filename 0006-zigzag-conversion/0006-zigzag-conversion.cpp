class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        int g=0;
        vector<vector<char>>mat(numRows);
        int i=0;
        bool flag=1;
        if(n==1 || numRows==1)
        return s;
        while(i<n){
            if(flag){
                while(i<n and g<numRows){
                    mat[g++].push_back(s[i]);
                    i++;
                }
                flag=0;
                i--;
            }
            else{
                int k=numRows-2;
                while(i<n and k>=0){
                    mat[k--].push_back(s[i]);
                    i++;
                }
                flag=1;
                g=1;
                i--;
            }
            i++;
        }
       string ans;
        for(auto it:mat){
            for(auto gt:it){
                ans.push_back(gt);
            }
        }
        return ans;
    }
};