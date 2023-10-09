class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0;
        int n=colors.size();
        int i=0,j=0;
        while(j<n){
            while(j<n && colors[i]==colors[j]){
                j++;
            }
            int cnt=j-i;
            if(cnt>2){
                if(colors[i]=='A') a+=(cnt-2);
                else b+=(cnt-2);
            }
            i=j;
        }
        return a>b;
    }
};