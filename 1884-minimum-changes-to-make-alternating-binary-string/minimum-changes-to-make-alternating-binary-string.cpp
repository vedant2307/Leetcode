class Solution {
public:
    int minOperations(string s) {
        int eans=0,oans=0,n=s.length();

        for(int idx=0;idx<n;idx++){
            if(idx%2){
                if(s[idx]=='1') eans++;
                else oans++;
            }
            else{
                if(s[idx]=='1') oans++;
                else eans++;
            }
        }

        return min(oans,eans);
    }
};