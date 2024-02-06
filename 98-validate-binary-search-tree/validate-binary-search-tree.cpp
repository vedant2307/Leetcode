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
    bool helper(TreeNode* root, long long mini, long long maxi){
        if(!root) return true;
        if(maxi>root->val && mini<root->val){
            return helper(root->left,mini,root->val) && helper(root->right,root->val,maxi); 
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {

        return helper(root,-1e10,1e10);
    }
};