class Solution(object):
    def putMarbles(self, w, k):
        ans=0
        n=len(w)
        for i in range(n-1):
            w[i]+=w[i+1]
        w.pop()
        w.sort()
        for i in range(k-1):
            ans += (w[n-2-i]-w[i])
        return ans