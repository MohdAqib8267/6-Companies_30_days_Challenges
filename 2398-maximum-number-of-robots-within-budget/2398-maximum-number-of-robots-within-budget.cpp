class Solution {
public:
 int maximumRobots(vector<int>& ch, vector<int>& runc, long long bd) {
   
        int left = 1, right = ch.size();
        int ans = 0;
        while(left <= right){
            deque<int> q;
            int mid = left + (right - left)/2;
            long long bdk = 0;
            bool ist = 0;
            long long sum=0;
            // first we choose a window of mid size
            int i=0,j=0;
            for(j=0;j<mid;j++){
                while(!q.empty() && ch[q.back()] <= ch[j]) q.pop_back();
                q.push_back(j);
                sum=sum+runc[j];
            }
            bdk = (ch[q.front()] + 1ll*(mid)*(sum));
            if(bdk <= bd) ist = 1;
            while(j < ch.size() && (!ist)){
                // now we remove mid - i th element and then add i'th element
                // removing element
                while(!q.empty() && j-q.front()+1 > mid) q.pop_front();
                // adding element
                while(!q.empty() && ch[q.back()] <= ch[j]) q.pop_back();
                q.push_back(j);
                sum=sum+runc[j]-runc[i];
                bdk = (ch[q.front()] + 1ll*(mid)*(sum));
                i++;
                j++;
                if(bdk <= bd) ist = 1;
            }
            if(ist){
                left = mid + 1;
                ans = mid;
            }else{
                right = mid-1;
            }
        }
        return ans;
    }
};