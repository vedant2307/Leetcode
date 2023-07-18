class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int freq=1,x=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(x!=nums[i]) freq--;
            else freq++;
            if(freq==0){
                x=nums[i]; freq=1;
            }
        }
        freq=0;
        for(int i=0;i<n;i++){
            if(nums[i]==x) freq++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int a=i+1;
            int b=n-a;
            if(nums[i]==x) cnt++;
            if(cnt>a/2 && (freq-cnt)>b/2) return i;
        }
        return -1;
    }
};