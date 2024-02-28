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
    int ans,maxi;
public:
    int height(TreeNode* root){
        if(!root) return 0;
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }

    void levelOrderTraversal(TreeNode* root,int lvl){
        if(!root) return;
        if(lvl==maxi) {
            ans=root->val; return;
        }
        levelOrderTraversal(root->right,lvl+1);
        levelOrderTraversal(root->left,lvl+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        maxi=height(root); cout<<maxi;
        levelOrderTraversal(root,1);
        return ans;
    }
};