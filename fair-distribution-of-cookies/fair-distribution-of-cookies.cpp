class Solution {
public:
    void helper(vector<int>&nums,int k,int &maxi,int idx,vector<int>&temp){
        if(idx==nums.size()){
            maxi=min(maxi,*max_element(temp.begin(),temp.end()));
            return;
        }

        for(int i=0;i<k;i++){
            temp[i]+=nums[idx];
            helper(nums,k,maxi,idx+1,temp);
            temp[i]-=nums[idx];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int maxi=1e9; vector<int>temp(k);
        helper(cookies,k,maxi,0,temp);
        return maxi;
    }
};