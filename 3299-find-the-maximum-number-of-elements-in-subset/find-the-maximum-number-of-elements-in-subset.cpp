#define ll long long
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<ll,ll>mp;
        sort(nums.begin(), nums.end());
        for(auto it:nums) mp[it]++;
        int ans=0;
        for(auto it:nums){
            if(it==1){
                if(mp.find(it)!=mp.end()){
                    ans=mp[it];
                    if( (mp[it]%2)==0) ans--;
                }
            }
            else{
                int k=1,maxi=0;
                while(true){
                    ll val = pow(it,k);
                    if(mp.find(val)!=mp.end()){
                        int freq=mp[val];
                        mp.erase(val);
                        if(freq>=2) maxi+=2;
                        else{
                            maxi++;
                            break;
                        }
                    }
                    else{
                        maxi--;
                        break;
                    } 
                    k = k*2;
                }
                ans=max(ans,maxi);
            }
            mp.erase(it);
        }
        return ans;
    }
};