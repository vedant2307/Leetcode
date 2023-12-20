class Solution {
public:
    vector<vector<int>>ans;
    int n;

    void helper(vector<int>&c, int target, vector<int>temp, int idx){
        
        if(target==0){ 
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<n;i++){
            if(i>idx && c[i]==c[i-1]) continue;
            if(c[i]<=target){
                temp.push_back(c[i]);
                helper(c, target-c[i], temp, i+1);
                temp.pop_back();
            }
            else break;
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, temp, 0);
        return ans;
    }
};