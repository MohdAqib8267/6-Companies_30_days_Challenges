class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<double>time;
        for(int i=0;i<n;i++){
            time.push_back((double)dist[i]/(double)speed[i]);
        }
        sort(time.begin(),time.end());
        int t=0;
        int cnt=0;
        for(int i=0;i<time.size();i++){
            if(t>=time[i]){
              break;  
            }
            cnt++;
            t++;
        }
        return cnt;
    }
};