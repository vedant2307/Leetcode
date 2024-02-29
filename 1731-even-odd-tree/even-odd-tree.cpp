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
    vector<int>ans;
    bool helper(TreeNode* root, int lvl){
        if(!root) return true;
        if( (lvl%2 && root->val%2) || (lvl%2==0 && root->val%2==0) ) return false;
        if(ans.size()==lvl) ans.push_back(root->val);
        else{
            if(lvl%2){
                if(ans[lvl]<=root->val) return false;
                ans[lvl]=root->val;
            }
            else{
                if(ans[lvl]>=root->val) return false;
                ans[lvl]=root->val;
            }
        }
        return helper(root->left,lvl+1) && helper(root->right,lvl+1);
    }
    bool isEvenOddTree(TreeNode* root) {
        return helper(root,0);
    }
};