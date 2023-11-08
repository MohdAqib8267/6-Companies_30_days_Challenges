class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
//         queue<pair<int,int>>q;
//         q.push({sx,sy});
//         int cnt=0;
//         int dx[]={-1,-1,0,1,1,1,0,-1};
//         int dy[]={0,-1,-1,-1,0,1,1,1};
//         while(!q.empty()){
//             int sz=q.size();
//             for(int i=0;i<sz;i++){
//                 auto p=q.front();
//                 q.pop();
//                 if(p.first==fx && p.second==fy){
//                     if(cnt<t){
//                      return true;
//                     } 
//                 }
//                 for(int k=0;k<8;k++){
//                     int nx=p.first+dx[k];
//                     int ny=p.second+dy[k];
//                     q.push({nx,ny});
//                 }
//             }
//             cnt++;
//         }
        
//         return false;
        
        if(sx==fx && fy==sy){
        if(t==1){
          return false;
        }
        return true;
      }
      if(max(abs(sx-fx),abs(fy-sy))<=t){
        return true;
      }
      return false;
    }
};