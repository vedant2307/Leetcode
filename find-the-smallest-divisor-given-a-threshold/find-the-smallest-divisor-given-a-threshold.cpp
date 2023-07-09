class Solution {
public:
    bool check(vector<int>& piles,int h,int mid){
        int cnt=0;
        for(auto it:piles){
            cnt += (it+(mid-1))/mid;
            if(cnt>h) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& piles, int H) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(piles,H,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};