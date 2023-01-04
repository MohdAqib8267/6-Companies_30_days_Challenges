class Solution {
public:
    // //idea----
    // This solution uses two stacks to keep track of the indices of the elements that need to be sorted. It first iterates through the array from left to right, and uses a stack to find the starting index of the subarray by keeping track of the indices of the elements that are out of order. It then iterates through the array from right to left, and uses another stack to find the ending index of the subarray in the same way. Finally, it returns the length of the subarray by subtracting the starting index from the ending index and adding 1.
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        stack<pair<int,int>>st;
        st.push({nums[0],0});
        int start=INT_MAX;
        int end=INT_MIN;
        //left to right(increasing find starting index which is minimum)
        for(int i=0;i<n;i++){
            while(!st.empty() and st.top().first>nums[i]){
                start=min(start,st.top().second);
                st.pop();
            }
           st.push({nums[i],i});
        }
        //create an empty stack with same name
         st=stack<pair<int,int>>();
        //right to left(Decreasing find end index which is maximum)
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() and st.top().first<nums[i]){
                end=max(end,st.top().second);
                st.pop();
            }
            st.push({nums[i],i});
        }
         
        if(end != INT_MIN and start != INT_MAX){
            return end-start+1;
        }
        return 0;
        
    }
    
};