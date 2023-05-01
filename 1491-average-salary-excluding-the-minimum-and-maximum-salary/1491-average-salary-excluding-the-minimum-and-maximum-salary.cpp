class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int sum=0;
        int n=salary.size();
        for(int i=1;i<n-1;i++){
            sum+=salary[i];
        }
        cout<<sum;
        return (double)sum/(n-2);
    }
};