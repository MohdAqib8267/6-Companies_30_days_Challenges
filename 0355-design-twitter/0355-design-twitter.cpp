class Twitter {
public:
    int timer;
    unordered_map<int,vector<pair<int,int>>> mp;
    unordered_map<int,unordered_set<int>> followee;
    Twitter() {
        timer = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({timer,tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        using p = pair<int,int>;
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<int> ans;
        for(auto it:mp[userId]){
            pq.push(it);
            if(pq.size() > 10)
                pq.pop();
        }
        for(auto gt:followee[userId]){
            for(auto it:mp[gt]){
                pq.push(it);
                if(pq.size() > 10)
                    pq.pop();
            }
        }
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        //bcz ye min heap hai maxheap me zrurat ni odeygi reverse ki
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followee[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followee[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */