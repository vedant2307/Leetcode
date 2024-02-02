class Solution {
public:
    int num_dig(int num){
        if(num==0) return 0;
        return 1+num_dig(num/10);
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        int l=num_dig(low), h=num_dig(high);
        for(int i=l;i<=h;i++){
            for(int start=1;start<=10-i;start++){
                int x=0;
                for(int num=0;num<i;num++){
                    x=x*10+(num+start);
                }
                if(x>=low && x<=high) ans.push_back(x);
            }
        }
        return ans;
    }
};