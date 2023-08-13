class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        //Binary search
        int lo=matrix[0][0];
        int hi=matrix[n-1][n-1];
        
        int ans=hi;
        while(lo<=hi){
            int temp=n-1;
            int mid=(lo+hi)/2;
            int cnt=0; //count krey ki mid se chote or equal element kitne hai matrix me
            for(int i=0;i<n;i++){
                while(temp>=0 and matrix[i][temp]>mid){
                    temp--;
                }
                cnt=cnt+(temp+1);
            }
            
            if(cnt<k){
                lo=mid+1;
            }
            else{
                ans=mid;
                hi=mid-1;
            }
        }
        return ans;
    }
};