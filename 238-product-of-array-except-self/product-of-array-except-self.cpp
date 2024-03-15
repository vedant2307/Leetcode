class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,1);
        int front=1,back=1;
        for(int i=0;i<n;i++){
            ans[i]*=front;
            front*=nums[i];
            ans[n-1-i]*=back;
            back*=nums[n-1-i];
        }
        return ans;
    }
};
// vector<int>ans(n),left(n),right(n);
// left[0]=right[n-1]=1;
// for(int i=1;i<n;i++){
//     left[i]=left[i-1]*nums[i-1];
// }
// for(int i=n-2;i>=0;i--){
//     right[i]=right[i+1]*nums[i+1];
// }
// for(int i=0;i<n;i++){
//     ans[i]=left[i]*right[i];
// }