class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        
        int l=1;
        int h=1000000000;
        int ans=INT_MIN;
        while(l<=h){
            int mid=l+(h-l)/2;
            int cnt=1;
            int prev=position[0];
            for(int i=1;i<position.size();i++){
                if(position[i]-prev>=mid){
                    
                    cnt++;
                    prev=position[i];
                }
            }
            if(cnt>=m){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};