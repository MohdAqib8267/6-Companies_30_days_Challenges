class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        
        
        int result=0;
        for(int i=0;i<n;i++){
             // Use a map to count the number of points that have the same slope
            // with respect to point i.
            unordered_map<double,int>mp;
            int localMax=0;
            int same=1; //every points 1 times count itself
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                else if(points[i][0]==points[j][0] and points[i][1]==points[j][1]){
                    same++;
                }
                else if(points[i][0]==points[j][0]){
                    mp[INT_MAX]++;
                }
                else{
                    double slope=(double)(points[i][1]-points[j][1])/(double)(points[i][0]-points[j][0]);
                    mp[slope]++;
                } 
            }
             // Find the maximum number of points that lie on the same line passing
            // through point i.
            for(auto it:mp){
                localMax=max(localMax,it.second);
            }
            localMax=same+localMax;
            //find result
            result=max(result,localMax);
        }
        return result;
    }
};