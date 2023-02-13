class Solution {
public:
    int countOdds(int low, int high) {
        int count=(high-low)/2;
        
       if(low%2==0 and high%2==0){
           return count;
       }
        return count+1;
    }
};