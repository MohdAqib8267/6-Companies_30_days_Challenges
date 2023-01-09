class Solution {
public:
    vector<string> split(string s){
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
        //make map with 2D string grid
        //store at same name in grid as vector{time,amount,city}
        //so 2D will form
        //itereate over the map
        //make a visited array
        //iterate 2D grid or map
        //if outer loop amount>1000 then this array mark true
        //else check every array of inner loop--> time diff and city
        //     if any one match then mark true
        //after 1 iteration of map
        //check vis array --> if any true that means it is invalid to store ans
        unordered_map<string,vector<vector<string>>>mp;
        for(int i=0;i<transactions.size();i++){
            vector<string>temp=split(transactions[i]);
            vector<string>str={temp[1],temp[2],temp[3]};
            mp[temp[0]].push_back(str);
        }
        
        //iterate over the map
        vector<string>ans;
        for(auto it:mp){
            
            vector<vector<string>>v=it.second;
            vector<bool>vis(v.size(),false);
            for(int i=0;i<v.size();i++){
                if(stoi(v[i][1])>1000){
                    vis[i]=true;
                }
                for(int j=i+1;j<v.size();j++){
                    if(abs(stoi(v[i][0])-stoi(v[j][0]))<=60 and v[i][2]!=v[j][2]){
                        vis[i]=true;
                        vis[j]=true;
                    }
                }
            }
            for(int i=0;i<v.size();i++){
                if(vis[i]){
                    ans.push_back(it.first+","+v[i][0]+","+v[i][1]+","+v[i][2]);
                }
            }
            
        }
        return ans;
    }
};