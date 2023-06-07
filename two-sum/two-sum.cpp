class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int>tmp;
        for(int i=0;i<nums.size();i++)
        {
            if(tmp.count(target-nums[i]))
            return {tmp[target-nums[i]],i};
            else
            tmp[nums[i]]=i;
        }
        return {};
    }
};
        // vector<int>ans;
        // vector<pair<int,int>>tmp;
        // for(int i=0;i<nums.size();i++){
        //     tmp.push_back({nums[i],i});
        // }
        // sort(tmp.begin(),tmp.end());
        // int i=0,j=nums.size()-1;
        // while(i<j){
        //     int tar=tmp[i].first+tmp[j].first;
        //     if(tar==target){ ans.push_back(tmp[i].second); ans.push_back(tmp[j].second);  break;}
        //     else if(tar>target) j--;
        //     else i++; 
        // }
        // return ans;