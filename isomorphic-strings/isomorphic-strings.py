class Solution(object):
    def isIsomorphic(self, s, t):
        n = len(s)
        m = len(t)
        if n != m:
            return False
        mp = {}
        mp1 = {}
        for idx in range(n):
            if s[idx] in mp:
                if mp[s[idx]] != t[idx]:
                    return False
            else:
                if t[idx] in mp1 and mp1[t[idx]]:
                    return False
                mp[s[idx]] = t[idx]
                mp1[t[idx]] = True
        return True