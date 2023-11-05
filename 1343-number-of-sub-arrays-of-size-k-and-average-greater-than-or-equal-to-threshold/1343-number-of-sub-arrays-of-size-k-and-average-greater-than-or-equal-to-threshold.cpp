class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int sum=0;
        int cnt=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
       
        for(int i=k;i<n;i++){
             if(sum/k >= threshold){
                cnt++;
            }
            sum=sum+arr[i];
            sum=sum-arr[i-k];
        }
        if(sum/k >= threshold){
                cnt++;
            }
        return cnt;
    }
};