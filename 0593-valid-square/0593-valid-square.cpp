class Solution {
public:
    double calculate(vector<int>& p1, vector<int>& p2){
        return sqrt((p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        //lets solve
        //beacuase we know that, In Square 4 length will same length that is called edge and 2 diagonal will have same length 
        //if this propert will follow then perfect square otherwise not.
        //so we create a set that will store lengths(edges and diagonals)
        //if length of set greater 2 that means it is not a perfect valid square
        vector<vector<int>>square={p1,p2,p3,p4};
        set<double>s;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(i==j) continue;
                
                double len=calculate(square[i],square[j]);
                if(len==0){
                    return false;
                }
                s.insert(len);
            }
        }
         return s.size()==2? true : false;
    }
};