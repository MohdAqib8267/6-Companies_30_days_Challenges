class Solution {
public:
    vector<int>nextSmaller(vector<int>& height){
        int n=height.size();
        stack<int>st;
        vector<int>v;
          st.push(n-1);
        v.push_back(n);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and height[st.top()]>=height[i]){
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
    vector<int>prevSmaller(vector<int>& height){
        int n=height.size();
        stack<int>st;
        vector<int>v;
        st.push(0);
        v.push_back(-1);
        for(int i=1;i<n;i++){
            while(!st.empty() and height[st.top()]>=height[i]){
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
    int largestRectangleAreaInHistogram(vector<int>&height){
        int n=height.size();
        vector<int>PS=prevSmaller(height);
        vector<int>NS=nextSmaller(height);
        int ans=0;
        for(int i=0;i<n;i++){
             int curr=(NS[i]-PS[i]-1)*height[i];
            ans=max(ans,curr);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>height(n,0);
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }
            int maxRowArea=largestRectangleAreaInHistogram(height);
            ans=max(ans,maxRowArea);
        }
        return ans;
    }
};