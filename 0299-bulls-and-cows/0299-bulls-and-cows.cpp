class Solution {
public:
//     Imagine that the secret number is "1807" and your friend makes a guess of "7810". In this case, there is one bull because the digit 8 is in the correct position. There are also three cows because the digits 7, 1, and 0 are present in the secret number, but are not in the correct position. The hint for this guess would be "1A3B", which means that there is 1 bull and 3 cows.

// Now let's consider another example where the secret number is "1123" and the guess is "0111". In this case, there is one bull because the digit 1 is in the correct position. There is also one cow because the digit 1 is present in the secret number, but is not in the correct position. The hint for this guess would be "1A1B", which means that there is 1 bull and 1 cow.
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