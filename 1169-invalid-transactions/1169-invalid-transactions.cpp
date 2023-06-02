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
        int n=transactions.size();
        unordered_map<string,vector<vector<string>>>mp;
        vector<string>ans;
        for(int i=0;i<n;i++){
            string tr=transactions[i];
            vector<string>temp=split(tr);
            //temp=["alice","20","800","mtv"]
            mp[temp[0]].push_back({temp[1],temp[2],temp[3]});
        }
        for(auto it:mp){
            vector<vector<string>>lists=it.second;
            vector<bool>vis(lists.size(),false);
            for(int i=0;i<lists.size();i++){
                if(stoi(lists[i][1])>1000){
                    vis[i]=true;
                }
                for(int j=i+1;j<lists.size();j++){
                    if(abs(stoi(lists[i][0])-stoi(lists[j][0]))<=60 and lists[i][2]!=lists[j][2]){
                        vis[i]=true;
                        vis[j]=true;
                    }
                }
            }
            
            for(int i=0;i<vis.size();i++){
                if(vis[i]){
                    ans.push_back(it.first+","+lists[i][0]+","+lists[i][1]+","+lists[i][2]);
                }
            }
        }
        return ans;
    }
};