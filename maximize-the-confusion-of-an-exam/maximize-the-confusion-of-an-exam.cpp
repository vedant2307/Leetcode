class Solution {
public:
    int helper(char ch, string s, int k, int n){
        int i=0,j=0,ans=0;
        while(j<n){
            while(j<n && k>=0){
                if(s[j]==ch) k--;
                j++;
            }
            if(k<0) ans=max(ans,j-i-1);
            else ans=max(ans,j-i);
            while(i<j && k<0){
                if(s[i]==ch) k++;
                i++;
            }
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int ans1=helper('F',answerKey,k,n);
        int ans2=helper('T',answerKey,k,n);
        return max(ans1,ans2);
    }
};