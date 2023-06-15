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
    void helper(TreeNode* root,int lvl){
        if(!root) return;
        if(ans.size()==lvl) ans.push_back(0);
        ans[lvl]+=root->val;
        helper(root->left,lvl+1);
        helper(root->right,lvl+1);
    }
    int maxLevelSum(TreeNode* root) {
        helper(root,0);
        int idx = max_element(ans.begin(),ans.end())-ans.begin();
        return idx+1;
    }
};