class Solution(object):
    def search(self, nums, target):
        n=len(nums)
        low=0
        high=n-1
        while(low<=high):
            if(nums[low]==target): return low
            elif(nums[high]==target): return high
            else:
                mid = low+(high-low)//2
                if(nums[low]<=nums[mid]):
                    if(nums[low]<=target and target<=nums[mid]): high=mid
                    else: low=mid+1
                else:
                    if(nums[mid]<=target and target<=nums[high]): low=mid
                    else: high=mid-1
        return -1
