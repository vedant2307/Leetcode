class Solution {
public:
    string Prefix(string a , string b)
    {
        int i=0;
        string ans;
        while(i<a.length() && i<b.length())
        {
            if(a[i]==b[i]) ans+=a[i++];
            else break;
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) 
    {
        string ans;
        sort(strs.begin(),strs.end());
        ans=Prefix(strs[0],strs[strs.size()-1]);    
        return ans;
    }
};