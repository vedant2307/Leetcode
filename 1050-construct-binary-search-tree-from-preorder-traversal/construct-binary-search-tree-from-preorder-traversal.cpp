/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>preorder, int &idx, int ubound){
        if(idx==preorder.size() || preorder[idx]>=ubound) return NULL;
        TreeNode* node=new TreeNode(preorder[idx++]);
        node->left=helper(preorder,idx,node->val);
        node->right=helper(preorder,idx,ubound);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return helper(preorder,idx,1001);
    }
};