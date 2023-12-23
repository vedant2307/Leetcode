class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>ans,temp;
        int size=0;
        for(auto it:obstacles){
            if(size==0 || temp[size-1]<=it){
                temp.push_back(it);
                size++;
                ans.push_back(size);
            }
            else{
                int idx = upper_bound(temp.begin(),temp.end(),it)-temp.begin();
                temp[idx]=it;
                ans.push_back(idx+1);
            }
        }
        return ans;
    }
};