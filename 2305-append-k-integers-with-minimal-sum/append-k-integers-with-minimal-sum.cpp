class Solution {
public:

    long long helper(long long num) {
        return (num*(num+1))/2;
    }

    long long minimalKSum(vector<int>& nums, int k) {
        long long sum=0LL;
        sort(nums.begin(),nums.end());
        vector<int>temp;
        for(auto it:nums){
            if(temp.empty() || temp.back()!=it) temp.push_back(it);
        }
        int low=0,high=temp.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=temp[mid]-(mid+1);
            if(cnt<k) low=mid+1;
            else high=mid-1; 
        }
        if(high==-1){
            long long num=k;
            sum=helper(num);
        }
        else{
            sum=helper(temp[high]);
            for(int i=0;i<=high;i++) sum-=temp[i];
            int miss=temp[high]-(high+1);
            k = k-miss;
            long long n1=temp[high],n2=temp[high]+k;
            sum = sum + (helper(n2)-helper(n1));
        }
        return sum;
    }
};
