class Solution {
public:
    bool check(vector<int>& piles, int h,int mid)
    {
        int tot=0;
        for(int i=0;i<piles.size();i++)
        {
            int var=(piles[i]+mid-1)/mid;
            tot+=var;
            if(tot>h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(check(piles,h,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }    
        return ans;
    }
};