class Solution {
public:
    bool isPair(int num1,int num2){
        string s1=to_string(num1);
        string s2=to_string(num2);
        unordered_map<char,int>mp1,mp2;
        int n1=s1.size(), n2=s2.size();
        int mxSize=max(n1,n2);
        while(n1 != mxSize){
            //add leading zeros to make equal size
            s1='0'+s1;
            n1++;
        }
        while(n2 != mxSize){
            //add leading zeros to make equal size
            s2='0'+s2;
            n2++;
        }
        int diff=0;
        for(int i=0;i<mxSize;i++){
            if(s1[i] != s2[i]){
                diff++;
            }
            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }
        return diff<=2 && mp1==mp2;
    }
    int countPairs(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cnt=cnt+isPair(nums[i],nums[j]);
            }
        }
        return cnt;
    }
};