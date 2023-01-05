class Solution {
public:
    int GCD(int a,int b){
       if (a == b)
    return b;
        //we know that a<b (sorting)
  return gcd(b , b-a);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        //find GCD in numsDivide array
        sort(numsDivide.begin(),numsDivide.end());
        int gcd=numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            gcd=GCD(gcd,numsDivide[i]);
        }
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==gcd or gcd%nums[i]==0){
                break;
            }
            count++;
        }
        return count==nums.size() ? -1 : count;
    }
};