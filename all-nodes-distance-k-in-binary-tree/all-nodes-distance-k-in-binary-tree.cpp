/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q; q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front(); q.pop();
            if(node->left){
                mp[node->left]=node; q.push(node->left);
            }
            if(node->right){
                mp[node->right]=node; q.push(node->right);
            }
        }
        queue<pair<TreeNode*,int>>qt;
        map<TreeNode*,bool>temp;
        qt.push({target,0});
        temp[target]=true;
        while(!qt.empty()){
            TreeNode* node=qt.front().first;
            int dist=qt.front().second;
            if(dist==k) break;
            qt.pop();
            if(node->left && !temp[node->left]) {
                temp[node->left]=true;
                qt.push({node->left,dist+1});
            }
            if(node->right && !temp[node->right]){
                temp[node->right]=true;
                qt.push({node->right,dist+1});
            }
            if(mp[node] && !temp[mp[node]]){
                temp[mp[node]]=true;
                qt.push({mp[node],dist+1});
            }
        }
        while(!qt.empty()){
            TreeNode* node=qt.front().first; qt.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};