class Solution {
public:
    bool search(vector<int>&A, int key) {
        int low=0,high=A.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(A[mid]==key) return 1;
            if(A[low]==A[mid] && A[mid]==A[high]) {
                low++; high--; continue;
            }
            if(A[low]<=A[mid]){
                if(key>=A[low] && key<A[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(key>A[mid] && key<=A[high]) low=mid+1;
                else high=mid-1;
            }
        }
        return 0;
    }
};