class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int i=0,n=nums.size();
        while(i<n){
            int strt=nums[i],end;
            while(i<n-1 && nums[i+1]==nums[i]+1){
                i++;
            }
            end=nums[i];
            if(strt==end){
                string s=to_string(strt);
                ans.push_back(s);
            }
            else{
                string s = to_string(strt) + "->" + to_string(end);
                ans.push_back(s);
            }
            i++;
        }
        return ans;
    }
};