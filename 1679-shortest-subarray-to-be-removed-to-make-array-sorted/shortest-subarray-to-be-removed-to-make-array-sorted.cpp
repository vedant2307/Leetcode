class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int r=n-1;
        while(r>0 && arr[r]>=arr[r-1]) r--;
        int ans = r;
        for(int l=0;l<r && (l==0 || arr[l-1]<=arr[l]); l++){
            while(r<n && arr[l]>arr[r]) r++;
            ans=min(ans,r-l-1);
        }
        return ans;
    }
};