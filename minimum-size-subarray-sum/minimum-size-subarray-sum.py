class Solution(object):
    def minSubArrayLen(self, target, nums):
        i=0
        j=0
        Sum=0
        n=len(nums)
        ans=n+1
        while(j<n):
            while(j<n and Sum<target):
                Sum=Sum+nums[j]
                j=j+1
            while(i<j and Sum>=target):
                ans=min(ans,j-i)
                Sum=Sum-nums[i]
                i=i+1
        if(ans==n+1):
            return 0
        return ans