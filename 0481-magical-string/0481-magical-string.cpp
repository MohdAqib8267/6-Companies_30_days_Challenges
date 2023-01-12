class Solution {
public:
    int magicalString(int n) {
        vector<int>arr(n+2);
        //base case
        arr[0]=1;
        arr[1]=2;
        
        int i=1,j=1;
        //idea-> 1. if arr[i]==2 that means number occured two times and if arr[i]==1 that means number occured one time
        //2. if arr[i]==2 and arr[j-1]==1 then then 2 numbers occured two times and arr[i]==2 and arr[j-1]==2 then 1 occurd two time
        //3. if arr[i]==1 and arr[j-1]==1 then 2 occured one timw and arr[i]==1 and arr[j-1]==2 then 1 occuren one time
        while(j<n){
            if(arr[i]==2){
                if(arr[j-1]==1){
                    arr[j]=2;
                    j++;
                    arr[j]=2;
                    j++;
                }
                else{
                    arr[j]=1;
                    j++;
                    arr[j]=1;
                    j++;
                }
            }
            else{ //arr[i]=1;
                if(arr[j-1]==1){
                    arr[j]=2;
                    j++;
                }
                else{
                    arr[j]=1;
                    j++;
                }
            }
            i++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                count++;
            }
        }
        return count;
        
    }
};