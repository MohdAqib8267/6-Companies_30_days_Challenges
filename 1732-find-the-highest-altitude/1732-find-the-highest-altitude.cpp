class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m=0,h=0;
        for(auto i : gain)
        {
            h+=i;
            m=max(m,h);
        }
        return m;
    }
};