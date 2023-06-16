class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int open=0;
        for(auto it:s){
            if(it==')'){
                if(open==0) cnt++;
                else open--;
            }
            else open++;
        }
        return cnt+open;
    }
};