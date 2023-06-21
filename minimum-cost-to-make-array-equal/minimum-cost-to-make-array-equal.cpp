class Solution {
public:
    #define ll long long
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        ll tot=0,ans=0;
        vector<pair<ll,ll>>temp;
        for(int i=0;i<n;i++){
            temp.push_back({nums[i],cost[i]});
            tot+=(ll)cost[i];
        }
        sort(temp.begin(),temp.end());
        ll mid=tot/2,x;
        for(auto it:temp){
            if(it.second<=mid) mid-=it.second;
            else{
                x=it.first; break;
            }
        }
        for(auto it:temp){
            ans+=(abs(it.first-x)*(it.second));
        }
        return ans;
    }
};