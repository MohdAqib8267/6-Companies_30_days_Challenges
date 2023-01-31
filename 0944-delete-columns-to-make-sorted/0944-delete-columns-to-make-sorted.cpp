class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row=strs.size();
        int col=strs[0].size();
        int delete_col=0;
        for(int j=0;j<col;j++){
            for(int i=0;i<row-1;i++){
                if(strs[i][j]>strs[i+1][j]){
                    delete_col++;
                    break;
                }
            }
            
        }
        return delete_col;
    }
};