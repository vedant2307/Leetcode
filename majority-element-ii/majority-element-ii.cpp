class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int cnt1=0,cnt2=0,cnt=nums.size()/3;
        int a=INT_MIN,b=INT_MIN;
        for(auto it:nums){
            if(cnt1==0 && it!=b) {
                a=it; cnt1++;
            }
            else if(cnt2==0 && it!=a) {
                b=it; cnt2++;
            }
            else if(it==a) cnt1++;
            else if(it==b) cnt2++;
            else {
                cnt1--; cnt2--;
            }
        }
        cnt1=0; cnt2=0;
        for(auto it:nums){
            if(it==a) cnt1++;
            else if(it==b) cnt2++;
        }
        if(cnt1>cnt) ans.push_back(a);
        if(cnt2>cnt) ans.push_back(b);
        return ans;
    }
};