class Solution {
public:
   bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for(int i=0;i<len && n>0;i++){
            if(i==0){
                if(flowerbed[i]) continue;
                if(i+1<len && flowerbed[i+1])continue;
                flowerbed[i]=1;
                n--;
            }else if(n==len-1){
                if(flowerbed[i]) continue;
                if(i-1>=0 && flowerbed[i-1])continue;
                flowerbed[i]=1;
                n--;
            }else{
                if(flowerbed[i]) continue;
                if(i+1<len && flowerbed[i+1])continue;
                if(i-1>=0 && flowerbed[i-1])continue;
                flowerbed[i]=1;
                n--;
            }
        }

        return n==0;
    }
};