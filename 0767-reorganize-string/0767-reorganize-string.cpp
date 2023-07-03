class Solution {
public:
    string reorganizeString(string s) {
          unordered_map<char,int>mp;
     priority_queue<pair<int,char>>pq;
     for(auto it:s){
         mp[it]++;
     }   
     pair<int,char>prev({0,'0'});
     for(auto it:mp){
         pq.push({it.second,it.first});
     }
        string ans="";

        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            ans=ans+p.second;
            p.first--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev=p;
        }
        if(ans.size()==s.size()){
            return ans;
        }
        return "";
    }
};