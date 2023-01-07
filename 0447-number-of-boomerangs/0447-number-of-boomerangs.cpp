class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int cnt=0;
        
        for(int i=0;i<n;i++){
            //use a hasmap to count the no of points have same distance wih 
            //respect to i(like max point on a line(149))
            unordered_map<int,int>mp;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                //calculate distance
                int dist=((points[i][0]-points[j][0])*(points[i][0]-points[j][0]) + (points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
                mp[dist]++;
            }
            
            // For each point j that has the same distance from i as another point k,
        // we can form a boomerang with the three points i, j, k.
            //iska matlab jb b freq 1 se zyada hogi to kisi ek points(i) k liye do ya do se zyada points aaye same distance ke
            //ab ek tym pe teen points dekhne hai ek to definetily i wala hoga or jo baki points hai(jinki freq map me count ki) unme se do do kr k lene honge
            //to hum kh skte hai ki nc2 lga dey(like i ke alwa 4 points hai to 4 me se do lene ke treqe count kr lenge). or ek baat ye ke order matter krta hai to i ke respect me (i,j,k) and (i,k,j) hoga to simply 2 se multiply kr denge
            //nc2*2=(n(n-1)/2)*2=n(n-1)
            for(auto it:mp){
                cnt=cnt+it.second*(it.second-1);
            }
        }
        return cnt;
    }
};