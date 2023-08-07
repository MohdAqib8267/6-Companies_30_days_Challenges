class Solution {
public:
//     Approach
// 1.H-index is at least 'cnt' paper being cited 'cnt' times
// 2.sort the vector, then count from the end of the vector
// 3.whenever citations[i] > cnt, add the counter
    int hIndex(vector<int>& citations) {
        int cntH=0;
        int n=citations.size();
        sort(citations.begin(),citations.end());
        for(int i=n-1;i>=0;i--){
            if(cntH<citations[i]){
                cntH++;
            }
        }
        return cntH;
    }
};