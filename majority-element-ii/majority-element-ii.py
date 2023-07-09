class Solution(object):
    def majorityElement(self, nums):
        cnt1=0 
        cnt2=0
        a = float('-inf')
        b = float('-inf')
        n=len(nums)
        for idx in nums:
            if(cnt1==0 and idx!=b): 
                cnt1=1
                a=idx
            elif(cnt2==0 and idx!=a): 
                cnt2=1
                b=idx
            elif(idx==a): cnt1+=1
            elif(idx==b): cnt2+=1
            else:
                cnt1-=1
                cnt2-=1
        cnt1=0
        cnt2=0
        for idx in nums:
            if(idx==a): cnt1+=1
            elif(idx==b): cnt2+=1
        lst=[]
        if(cnt1>n//3): lst.append(a)
        if(cnt2>n//3): lst.append(b) 
        return lst