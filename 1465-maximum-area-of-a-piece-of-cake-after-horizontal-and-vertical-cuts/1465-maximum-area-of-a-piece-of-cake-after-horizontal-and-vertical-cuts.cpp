class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int mod=1e9+7;
        
        int Hst=0;
        int Hen=h;
        int maxHeight=horizontalCuts[0]-Hst;
        for(int i=1;i<horizontalCuts.size();i++){
            maxHeight=max(maxHeight,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        maxHeight=(max(maxHeight,Hen-horizontalCuts[horizontalCuts.size()-1]));
        
        int Wst=0;
        int Wen=w;
        int maxWidth = verticalCuts[0]-Wst;
        for(int i=1;i<verticalCuts.size();i++){
            maxWidth=(max(maxWidth,verticalCuts[i]-verticalCuts[i-1]));
        }
        maxWidth=(max(maxWidth,Wen-verticalCuts[verticalCuts.size()-1]));
        
       
        return (((long long)maxWidth%mod)*((long long)maxHeight%mod))%mod;
    }
};