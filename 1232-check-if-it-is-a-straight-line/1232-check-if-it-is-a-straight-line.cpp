class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y=coordinates[1][1]-coordinates[0][1];
        int x=coordinates[1][0]-coordinates[0][0];
        for(int i=2;i<coordinates.size();i++){
            int y1=coordinates[i][1]-coordinates[0][1];
            int x1=coordinates[i][0]-coordinates[0][0];
            if(y*x1!=x*y1){
                return false;
            }
        }
        return true;
    }
};