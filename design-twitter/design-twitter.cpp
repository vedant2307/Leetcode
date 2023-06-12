class Twitter {
public:
    map<int,map<int,int>>follower_list;
    map<int,map<int,int>>news_list;
    int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        news_list[userId][tweetId]=time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans; priority_queue<pair<int,int>>pq;
        for(auto it1:news_list[userId]){
            pq.push({it1.second,it1.first});
        }
        for(auto it:follower_list[userId]){
            int followee=it.first;
            for(auto it1:news_list[followee]){
                pq.push({it1.second,it1.first});
            }
        }
        while(!pq.empty()){
            auto it=pq.top(); pq.pop(); 
            int id=it.second;
            ans.push_back(id);
            if(ans.size()==10) break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower_list[followerId][followeeId]++;
    }
    
    void unfollow(int followerId, int followeeId) {
        follower_list[followerId].erase(followeeId);
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