class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length())
            return false;
        unordered_map<char,int> mp,mp2;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++,mp2[goal[i]]++;
        }
        if(s==goal){
            for(auto i:mp2)
                if(i.second>=2)
                    return true;
            return false;
        }
        if(mp!=mp2)
            return false;
        int c=-1,k=0;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]){
                if(c==-1)
                    c=i;
                else{
                    if(goal[i]==s[c] && goal[c]==s[i]){
                        k++;
                        if(k>1)
                            return false;   
                        c=-1;
                    }  
                    else
                        return false;   
                }
            }
        }
        return true;

    }
};