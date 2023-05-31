class Solution {
public:
    vector<int>prevSmaller(vector<int>& heights){
        stack<int>st;
        vector<int>v;
        st.push(0);
        v.push_back(-1);
        for(int i=1;i<heights.size();i++){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(st.top());
            }
            st.push(i);
        }
        return v;
    }
    vector<int>nextSmaller(vector<int>& heights){
        stack<int>st;
        vector<int>v;
        int n=heights.size();
        v.push_back(n);
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                v.push_back(n);
            }
            else{
                v.push_back(st.top());
            }
            st.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left=prevSmaller(heights);
        vector<int>right=nextSmaller(heights);
       
        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,(right[i]-left[i]-1)*heights[i]);
        }
        return ans;
    }
};