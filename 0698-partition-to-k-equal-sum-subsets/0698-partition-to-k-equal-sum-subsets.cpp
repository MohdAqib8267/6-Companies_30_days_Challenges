class Solution {
public:
   bool solve(vector<int>&nums,vector<bool>&visited,int index,int k,int currsum,int avg){

        //Base case
        if(k==0)return true;
        if(currsum>avg)return false;
        
        if(currsum==avg)
        {
            //Found One subset..try to Find remaining k-1 subset
            return solve(nums,visited,0,k-1,0,avg);
        }
        
        for(int i=index;i<nums.size();i++)
        {
            if(visited[i])continue;
            
            
            visited[i]=true;
            if(solve(nums,visited,i+1,k,currsum+nums[i],avg))return true;
            visited[i]=false;
        }
        return false;
        
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //int sum=accumulate(nums.begin(),nums.end(),0);
        int sum=0;
        for(auto x:nums){
            sum+=x;
        }
        int n=nums.size();
        if(k>n)return false;
        if((sum % k) !=0)return false;
        
        sort(nums.begin(),nums.end(),greater<int>());
		int avg=sum/k;
       if(nums[0]>avg)return false;
        
        vector<bool>visited(n,0);
        return solve(nums,visited,0,k,0,avg);
    }

};