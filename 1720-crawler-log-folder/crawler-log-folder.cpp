class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string>st;
        int cnt=0,n=logs.size();
        for(int i=0;i<n;i++){
            if(logs[i] == "./"){
                continue;
            }
            else if(logs[i]== "../"){
                if(cnt) cnt--;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};