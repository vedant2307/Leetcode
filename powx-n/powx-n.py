class Solution(object):
    def helper(self, x, n):
        if(x==0): return 0
        if(n==0): return 1
        ans=self.helper(x,n//2)
        if(n%2): return ans*ans*x
        return ans*ans
    def myPow(self, x, n):
        ans=self.helper(x,abs(n))
        if(n<0): return 1/ans
        return ans