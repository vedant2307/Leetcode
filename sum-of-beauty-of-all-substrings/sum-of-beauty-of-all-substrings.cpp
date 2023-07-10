class Solution {
public:
    int beautySum(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>fr;
            multiset<int>ms;
            for(int j=i;j<n;j++){
                if(ms.find(fr[s[j]])!=ms.end())
                    ms.erase(ms.find(fr[s[j]]));
                fr[s[j]]++;
                ms.insert(fr[s[j]]);
                ans+=(*ms.rbegin()-*ms.begin());
            }
        }
        return ans;
    }
};