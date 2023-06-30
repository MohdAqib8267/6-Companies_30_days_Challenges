class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
     unordered_set<int> visited(forbidden.begin(), forbidden.end());
        
        queue<pair<int, bool>> que; 
        que.push({0, true});

        int count = 0;
        while (!que.empty()) {
           
            int length = que.size();
            for(int i = 0; i < length; i++){
                auto [current, back] = que.front(); 
                que.pop();
            
                if (visited.find(current) != visited.end()) {
                    continue;
                }

                if (current == x) {
                    return count;
                }

                // try going back if possible
                if (back and 0 <= current - b) {
                    que.push({current - b, false});
                }
                // try going forward if possible
                if (current +a <= 6000) {
                    que.push({current + a, true});
                }

                visited.insert(current);
            }
            count++;
        }
         return -1;
    }
};