class Solution {
public:
    #define ll long long
    vector<int> getAverages(vector<int>& nums, int k) 
    {
        int n=nums.size();
        vector<int>ans;
        vector<ll>prefix(n+1,0LL);
        for(int i=1;i<n+1;i++)
            prefix[i]+= (prefix[i-1]+nums[i-1]);
        for(int i=0;i<n;i++)
        {
            if(i-k>=0 && i+k<n)
            {
                ll t = prefix[i+k+1]-prefix[i-k];
                ans.push_back(t/(2*k+1));
            }
            else
                ans.push_back(-1);
        }
        return ans;
    }
};