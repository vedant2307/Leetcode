class Solution {
public:
    int helper(int n,int m){
        if(m==0 || n<=1) return 1;
        int a=1,b=1;
        if(n>=m) a=helper(n-m,m)*m;
        b=helper(n,m-1);
        return max(a,b);
    }
    int integerBreak(int n) {
        return helper(n,n-1);
    }
};