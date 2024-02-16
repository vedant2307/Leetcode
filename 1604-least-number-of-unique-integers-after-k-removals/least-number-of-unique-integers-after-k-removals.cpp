class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        unordered_map<int,int>temp;
        for(int i=0;i<arr.size();i++)
            temp[arr[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(auto &it : temp)
        {
            pq.push(make_pair(it.second,it.first));    
        }
        
        while(k>0)
        {
            if(k-pq.top().first>=0)
            {
                k-=pq.top().first;
                pq.pop();
            }
            else
                break;
        }
        return pq.size();
    }
};