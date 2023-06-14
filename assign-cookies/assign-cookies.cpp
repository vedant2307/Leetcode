class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,n=s.size(),m=g.size();
        while(i<n && j<m){
            if(s[i]>=g[j]){
                cnt++; j++; 
            }
            i++;
        }
        return cnt;
    }
};