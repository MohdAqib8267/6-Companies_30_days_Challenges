class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>v;
        int n=matrix.size();
        int m=matrix[0].size();
        int row_start=0;
        int row_end=n-1;
        int col_start=0;
        int col_end=m-1;
         while(row_start<row_end and col_start<col_end){
        for(int col=col_start;col<=col_end;col++){
            v.push_back(matrix[row_start][col]);
        }
        row_start++;
        for(int row=row_start;row<=row_end;row++){
            v.push_back(matrix[row][col_end]);
        }
        col_end--;
        for(int col=col_end;col>=col_start;col--){
            v.push_back(matrix[row_end][col]);
        }
        row_end--;
        for(int row=row_end;row>=row_start;row--){
            v.push_back(matrix[row][col_start]);
        }
        col_start++;
    }
     if(row_start==row_end){
        for(int col=col_start;col<=col_end;col++){
            v.push_back(matrix[row_start][col]);
        }
    }
    else if(col_start==col_end){
        for(int row=row_start;row<=row_end;row++){
            v.push_back(matrix[row][col_start]);
        }
    }
    return v;
    }
};