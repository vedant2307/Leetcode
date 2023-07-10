# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def helper(self,root):
        if(root==None): return 1e5
        if(root.left==None and root.right==None): return 1
        left=self.helper(root.left)
        right=self.helper(root.right)
        return min(left,right)+1
    def minDepth(self, root):
        ans=self.helper(root)
        if (ans>=1e5): return 0 
        return ans