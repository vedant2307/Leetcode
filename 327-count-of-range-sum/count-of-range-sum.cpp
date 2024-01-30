#define ll long long
class Solution {
public:
    int ans;
    vector<ll>prefix;
    void Merge(int low, int mid, int high){
        int left_s=mid-low+1, right_s=high-mid;
        vector<ll>left(left_s),right(right_s);
        for(int k=0;k<left_s;k++) left[k] = prefix[k+low];
        for(int k=0;k<right_s;k++) right[k] = prefix[k+mid+1];

        int i=0,j=0,k=low;

        while(i<left_s && j<right_s){
            if(left[i]<right[j]) prefix[k++] = left[i++];
            else prefix[k++] = right[j++]; 
        }
        
        while(i<left_s) prefix[k++] = left[i++];
    }

    void MergeSort(int low, int high, int lower, int upper){
        if(low<high){
            int mid=low+(high-low)/2;
            MergeSort(low,mid,lower,upper);
            MergeSort(mid+1,high,lower,upper);

            int i=mid+1,j=mid+1;
            for(int k=low; k<=mid; k++){
                while(i<=high && prefix[i]-prefix[k]<lower) i++;
                while(j<=high && prefix[j]-prefix[k]<=upper) j++;
                ans += (j-i);
            }
            Merge(low, mid, high);
        }
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        prefix.resize(n+1,0);
        ans=0;
        for(int idx=1;idx<=n;idx++) prefix[idx]=prefix[idx-1]+nums[idx-1];
        MergeSort(0, n, lower, upper);
        return ans;
    }
};