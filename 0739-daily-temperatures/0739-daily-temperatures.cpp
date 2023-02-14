class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        int i=n-2;
        vector<int>ans(n,0);
        stack<int>st;
        st.push(n-1);
        while(!st.empty() and i>=0){
            while(!st.empty() and temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top()-i;
            }
            st.push(i);
            i--;
        }
        return ans;
    }
};