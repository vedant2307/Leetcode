class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,ans=-1,maxFreq=0;
        int n=s.length();
        unordered_map<int,int>tmp;
        while(j<n){
            tmp[s[j]]++;
            maxFreq=max(maxFreq,tmp[s[j]]);
            int curr_len=j-i+1;
            if(curr_len-maxFreq>k){
                tmp[s[i]]--; 
                i++;
                curr_len--;
            }
            ans=max(ans,curr_len);
            j++;
        }
        return ans;
    }
};