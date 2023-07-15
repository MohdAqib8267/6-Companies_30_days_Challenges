class Solution {
public:
    vector<int>prevSmall(vector<int>& heights){
        int n=heights.size();
        vector<int>ans(n);
        ans[0]=-1;
        stack<int>st;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() and heights[i]<=heights[st.top()]){
                st.pop();
            } 
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
       
    }
    vector<int>nextSmall(vector<int>& heights){
        int n=heights.size();
        vector<int>ans(n);
        ans[n-1]=n;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and heights[i]<=heights[st.top()]){
                st.pop();
            } 
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
       
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>prevSmaller=prevSmall(heights);
        vector<int>nextSmaller=nextSmall(heights);
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,(nextSmaller[i]-prevSmaller[i]-1)*heights[i]);
        }
        return res;
    }
};