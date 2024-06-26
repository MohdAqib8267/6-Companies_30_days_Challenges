class Solution {
public:
       vector<int>prevSmall(vector<int>&heights){
        vector<int>res(heights.size());
     
        stack<int>st;
        st.push(0);
        res[0]=-1;
        for(int i=1;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=-1;
            }
            else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
    }
    vector<int>nextSmall(vector<int>&heights){
        vector<int>res(heights.size());
        res[heights.size()-1]=heights.size();
        stack<int>st;
        st.push(heights.size()-1);
      
        for(int i=heights.size()-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                res[i]=heights.size();
            }
            else{
                res[i]=st.top();
            }
            st.push(i);
        }
        return res;
    }
    int largestRectangleAreaInHistogram(vector<int>heights){
        int n=heights.size();
        int ans=0;
        vector<int>prev = prevSmall(heights);
        vector<int>next = nextSmall(heights);
        //prev [-1,-1,1,2,1,4]
        //next [1,6,4,4,6,6]
        
        for(int i=0;i<n;i++){
            int area = (next[i]-prev[i]-1)*heights[i];
            ans=max(ans,area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<int>height(n,0);
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