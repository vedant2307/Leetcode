class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.length(), m=goal.length();
        if(n!=m) return false;
        if(s==goal){
            set<char>temp(s.begin(),s.end());
            return temp.size()<n;
        }
        int i=0,j=n-1;
        while(i<j && s[i]==goal[i]) i++;
        while(i<j && s[j]==goal[j]) j--;
        swap(s[i],s[j]);
        return s==goal;
    }
};