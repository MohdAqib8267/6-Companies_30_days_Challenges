class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int front=-1;
        int cnt=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            if(p.first==0){
                continue;
            }
            if(front==-1){
                front=p.first;
            }
            else{
                if(front==p.first){
                    cnt++;
                    pq.push({--p.first,p.second});
                }
                else{
                    front=p.first;
                }
            }
        }
        return cnt;
    }
};