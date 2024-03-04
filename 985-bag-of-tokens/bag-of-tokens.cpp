class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size();
        int i=0,j=n-1,sco=0,ans=0;
        while(i<=j){
            if(power>=tokens[i]){
                sco++; power-=tokens[i++];
            }
            else{
                if(sco>0) {sco--; power+=tokens[j--];}
                else break;
            }
            ans=max(ans,sco);
        }
        return ans;
    }
};