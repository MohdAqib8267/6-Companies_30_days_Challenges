class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;
        vector<vector<int>>ans;  
        while(i<firstList.size() && j<secondList.size()){
            int st = max(firstList[i][0],secondList[j][0]);
            int en = min(firstList[i][1],secondList[j][1]);
            if(st<=en){
                ans.push_back({st,en});
            }
            if(firstList[i][1]<=secondList[j][1]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};