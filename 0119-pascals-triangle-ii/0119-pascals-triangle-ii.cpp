class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=0;i<34;i++){
            for(int j=0;j<=i;j++){
                if(j==0 || j==i){
                    temp.push_back(1);
                }
                else{
                    temp.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }
            }
           if(i==rowIndex){
               return temp;
           }
            ans.push_back(temp);
            temp.clear();
        }
        return temp;
    }
};