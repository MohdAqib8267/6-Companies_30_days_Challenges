class Solution {
public:
    // 1-------6
    //   2----------8
    //            7--------12
    //                 10--------16
    //--------------------------------------->x
    //idea
    // To solve this problem, you can first sort the balloons by their ending x-coordinate. Then, you can iterate through the sorted balloons and keep track of the rightmost x-coordinate that has been reached by an arrow. Whenever you encounter a balloon that starts before the rightmost x-coordinate, you can skip it because it has already been burst by an arrow that burst a preceding balloon. Otherwise, you will need to shoot an arrow at the start of the current balloon, update the rightmost x-coordinate reached, and increment the arrow count.
     static bool cmp(vector<int>& a,vector<int>& b){
        if(a[1]<b[1]){
            return true;
        }
        return false;
    }
       int findMinArrowShots(vector<vector<int>>& points) {
        //basically this is non overlaping interval problem
        sort(points.begin(),points.end(),cmp); //sort according to second element
        int ans=1; //take 1 ki phla to phodenge hi
        int end=points[0][1];
        
        for(int i=1;i<points.size();i++){
            if(points[i][0]>end){ //to phodna pdeyga
                ans++;
                end=points[i][1];
            }
        }
        
        return ans;
    }
};