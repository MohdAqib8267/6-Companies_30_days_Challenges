class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long low=0,high=0;
        long long sum=0;
        long long ans=0;
        for(auto i:batteries){
            sum+=i;
        }
        high=sum;
        sort(batteries.begin(),batteries.end());//binary search
        // if(n==1){
        //     return sum;
        // }
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long cnt=0;
            long long temp=0;
            for(auto i:batteries){
                temp+=i;
                if(temp>=mid){
                    temp=temp-mid;
                    cnt++;
                }
            
                //OR
        //  val = 0, val = (longlong)n*mid; //itni battries ki need hai
        // for(int i = 0; i < m; i++)
        // {
        //     if(batteries[i] < mid)
        //         val += batteries[i];
        //     else
        //         val += mid;
        // }
        // if(val >= check){ ans=mid; low=mid+1;}
        // else{high=mid-1} 
            
    
            }
            if(cnt>=n){
                //mtlab hum mid ko zyada computers me distrubute kr paa rhey hau
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};