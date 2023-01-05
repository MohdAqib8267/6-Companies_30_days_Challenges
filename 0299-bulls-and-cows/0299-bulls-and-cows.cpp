class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int,int>mp;
        int bull=0, cow=0;
        int n=secret.size();
        
        //iterate over the screte
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bull++;
            }
            else{
                mp[secret[i]]++;
            }
        }
        //itereate over the guess
        for(int i=0;i<n;i++){
            if(mp.find(guess[i])!=mp.end() and mp[guess[i]]>0 and secret[i]!=guess[i]){
                cow++;
                mp[guess[i]]--;
            }
        }
       
        return to_string(bull)+'A'+to_string(cow)+'B';
    }
};