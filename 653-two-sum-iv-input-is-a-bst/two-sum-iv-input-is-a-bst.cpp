class BSTIterator {
public:
    stack<TreeNode*>st;
    bool flg;
    BSTIterator(TreeNode* root,bool flag) {
        flg=flag;
        pushAll(root);  
    }
    
    int pointer() {
        TreeNode* curr=st.top(); st.pop();
        if(flg) pushAll(curr->right);
        else pushAll(curr->left);
        return curr->val;
    }
    
    void pushAll(TreeNode* curr){
        if(flg){
            while(curr){
                st.push(curr); curr=curr->left;
            }
        }
        else{
            while(curr){
                st.push(curr); curr=curr->right;
            }
        }
        return;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator next(root,true);
        BSTIterator prev(root,false);
        int x=next.pointer();
        int y=prev.pointer();
        while(x<y){
            if(x+y==k) return true;
            else if(x+y<k) x=next.pointer();
            else y=prev.pointer();
        }
        return false;
    }
};