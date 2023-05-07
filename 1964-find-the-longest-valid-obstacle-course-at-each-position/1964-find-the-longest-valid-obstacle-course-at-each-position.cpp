class Solution {
public:
     int bSearch(vector<int> &nums,int key){
        int l = 0 ,  r = nums.size() ;
        while(l<r){
            int mid = l+ (r-l)/2 ;
            if(nums[mid]>key){
                r = mid ;
            }
            else{
                l = mid+1;
            }
        }
        return l ;
    }
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size() , i ;
        vector<int> res(n,0) ;
        vector<int> sz ;
        for(i=0;i<n;i++){
            int key = obstacles[i] ;
            int ind = bSearch(sz,key) ;
            if(ind==sz.size()){
                sz.push_back(key);
            }
            else{
                sz[ind] = key ;
            }
            res[i] = ind+1; 
        }
        return res;
    }
};