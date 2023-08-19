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
#define ll long long
const int mod = 1e9+7;
class Solution {
public:
    ll sum,ans;
    void total_sum(TreeNode* root){
        if(!root) return;
        sum+=root->val;
        total_sum(root->left);
        total_sum(root->right);
    }
    ll helper(TreeNode* root){
        if(root==NULL) return 0;
        ll left=helper(root->left);
        ll right=helper(root->right);
        ll temp=left+right+root->val;
        ll var=(temp*(sum-temp));
        ans =  max(ans,var);
        return temp;
    }
    int maxProduct(TreeNode* root) {
        sum=0LL; ans=0LL;
        total_sum(root);
        ll temp=helper(root);
        ans=ans%mod;
        return (int)ans;
    }
};