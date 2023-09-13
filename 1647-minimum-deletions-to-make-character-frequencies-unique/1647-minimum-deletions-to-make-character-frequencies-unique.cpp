class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<int>temp;
        for(auto it:mp){
            temp.push_back(it.second);
        }
        
        set<int>st;
        int cnt=0;
        for(int i=0;i<temp.size();i++){
            if(st.empty()){
                st.insert(temp[i]);
            }
            else{
                if(st.find(temp[i])!=st.end()){
                    cnt++;
                    temp[i]--;
                    i--;
                }else{
                    if(temp[i]!=0)
                    st.insert(temp[i]);
                }
            }
        }
        return cnt;
    }
};