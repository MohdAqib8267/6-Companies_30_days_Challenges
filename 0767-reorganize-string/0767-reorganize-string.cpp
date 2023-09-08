class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        priority_queue<pair<int,char>>pq;
        pair<int,char>prev={0,'0'};
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            ans=ans+temp.second;
            temp.first--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev=temp;
        }
        if(ans.size()==s.size()){
            return ans;
        }
        return "";
    }
};