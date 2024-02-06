class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
       vector<vector<string>>ans;
       vector<pair<string,int>>temp;
       for(int i=0;i<strs.size();i++)
       {
           string curr=strs[i];
           sort(curr.begin(),curr.end());
            temp.push_back({curr,i});
       } 
       sort(temp.begin(),temp.end());
       int k=0,i=0;
       while(i<temp.size())
       {
           int j=i;
           ans.push_back({});
           while(j<temp.size() && temp[i].first==temp[j].first)
           {
               ans[k].push_back(strs[temp[j].second]);
               j++;
           }
           k++;
            i=j;
       }
       return ans;
    }
};