class Solution {
public:
    vector<string>split(string s){
         vector<string>str;
        string p="";
        for(int i=0;i<s.size();i++){
            if(s[i]==','){
                str.push_back(p);
                p="";
            }
            else{
                p=p+s[i];
            }
        }
        str.push_back(p);
        return str;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string>ans;
        unordered_map<string,vector<vector<string>>>mp;
        
        for(int i=0;i<transactions.size();i++){
             vector<string>temp =split(transactions[i]);
            vector<string>rem={temp[1],temp[2],temp[3]};
                mp[temp[0]].push_back(rem);
         }
        
        
        for(auto it:mp){
            vector<vector<string>>list = it.second;
            vector<bool>vis(list.size(),false);
            for(int i=0;i<list.size();i++){
                if(stoi(list[i][1])>1000){
                    vis[i]=true;
                }
                for(int j=i+1;j<list.size();j++){
                    if(abs(stoi(list[i][0])-stoi(list[j][0]))<=60 and list[i][2] != list[j][2]){
                        vis[i]=true;
                        vis[j]=true;
                    }
                }
            }
            for(int i=0;i<vis.size();i++){
                if(vis[i]){
                    ans.push_back(it.first+","+list[i][0]+","+list[i][1]+","+list[i][2]);
                }
            }
        }
        
        return ans;
    
    }
};