class Solution {
public:
    bool isNStraightHand(vector<int>&hand, int k) {
        int n=hand.size();
        if(n%k) return false;
        unordered_map<int,int>mp;
        for(auto it:hand) mp[it]++;
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++){
            if(mp[hand[i]]>0){
                mp[hand[i]]--;
                for(int j=1;j<k;j++){
                    int num=hand[i]+j;
                    if(mp[num]==0) return false;
                    mp[num]--;
                }
            }
        }
        return true;
    }
};