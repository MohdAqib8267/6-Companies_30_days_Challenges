class Solution {
public:
     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair <int, int>> arr(n);
        for(int i=0; i<n; i++)
        {
            arr[i] = {nums2[i], nums1[i]};
        }

        sort(arr.rbegin(), arr.rend());

        priority_queue<int ,vector<int>, greater<int>> pq;

        long long curr = 0;
        long long best = 0;

        for(int i=0; i<n; i++)
        {
            pq.push(arr[i].second);
            curr += arr[i].second;

            if(pq.size() > k)
            {
                int mini = pq.top();
                pq.pop();
                curr -= mini;
            }
            if(pq.size() == k)
            {
                best = max(best, curr*arr[i].first);
            }
        }
        return best;
    }
};