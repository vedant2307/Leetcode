class Solution(object):
    def helper(self,s,k,ch):
        i=0
        ans=0
        for j in range(len(s)):
            if(s[j]==ch):
                k-=1
            while(i<j and k<0):
                if(s[i]==ch):
                    k+=1
                i+=1
            ans=max(ans,j-i+1)
        return ans
    
    def maxConsecutiveAnswers(self, answerKey, k):
        ans1 = self.helper(answerKey,k,'F')
        ans2 = self.helper(answerKey,k,'T')
        return max(ans1,ans2)