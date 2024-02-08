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
    private : 
        TreeNode *prev,*first,*middle,*last;
    void inorder(TreeNode* root){
        if(!root) return ;
        inorder(root->left);
        if(prev->val>root->val){
            if(!first){
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first=middle=last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val,last->val);
        else swap(first->val,middle->val);
    }
};