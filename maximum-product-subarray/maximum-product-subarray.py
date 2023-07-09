class Solution(object):
    def maxProduct(self, nums):
        maxi=1
        mini=1
        ans=-11
        for idx in nums:
            if(idx<0): 
                temp=maxi
                maxi=mini
                mini=temp
            maxi=max(maxi*idx,idx)
            mini=min(mini*idx,idx)
            ans = max(ans,maxi)
        return ans