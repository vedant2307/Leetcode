class Solution {
public:
    int helper(char ch, string s, int k, int n){
        int i=0,j=0,ans=0;
        for(;j<n;j++){
            if(s[j]==ch) k--;
            while(k<0){
                if(s[i++]==ch) k++;
            }
            ans=max(ans,j-i+1);
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