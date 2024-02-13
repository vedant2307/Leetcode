class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i=0,j=0,n=arr.size();
	    while(j<n){
	        if(arr[j]==0) j++;
	        else
	        {
	            if(i!=j)
	                swap(arr[i],arr[j]); 
                i++; j++;
	        }
	    }
    }
};