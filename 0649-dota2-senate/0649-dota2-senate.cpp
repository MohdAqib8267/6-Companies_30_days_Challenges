class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>q1; //radiant
        queue<int>q2; //Dire
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                q1.push(i);
            }
            else{
                q2.push(i);
            }
        }
        
        while(!q1.empty() and !q2.empty()){
            int rad=q1.front(); q1.pop();
            int dir=q2.front(); q2.pop();
            if(rad<dir){
                q1.push(rad+n);
            }
            else{
                q2.push(dir+n);
            }
        }
        if(q1.size()==0){
            return "Dire";
        }
        else{
            return "Radiant";
        }
    }
};