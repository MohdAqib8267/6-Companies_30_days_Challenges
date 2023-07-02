class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        int ind=0;
        while(i<n){
            int j=i+1;
            while(j<n and chars[j]==chars[i]){
                j++;
            }
            chars[ind++]=chars[i];
            int cnt=j-i;
            if(cnt>1){
                string len=to_string(cnt);
                
                //yeah islye kya kyu ki hame 1 2 alag hona agar 12 answer aaay toh 
                for(auto ch:len){
                    chars[ind++]=ch;
                }
            }
            i=j;
        }
        return ind;
    }
};