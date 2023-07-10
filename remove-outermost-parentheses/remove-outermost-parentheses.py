class Solution(object):
    def removeOuterParentheses(self, s):
        ans=''
        a=0
        for st in s:
            if(st=='('):
                if(a>0): ans+=st
                a+=1
            else:
                if(a>1): ans+=st
                a-=1
        return ans