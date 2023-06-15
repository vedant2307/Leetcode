class Solution {
public:
    int maxDepth(string s) {
        int ans=0,open=0;
        for(auto it:s){
            if(it=='('){
                open++;
                ans=max(ans,open);
            }
            else if(it==')') open--;
        }
        return ans;
    }
};