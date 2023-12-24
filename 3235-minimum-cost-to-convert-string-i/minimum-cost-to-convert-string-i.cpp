class Solution {
public:
    #define ll long long
    int inf = INT_MAX;
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size(),N=26;
        vector<vector<int>>mat(N,vector<int>(N,inf));
        for(int i=0;i<n;i++){
            int src=original[i]-'a', dest=changed[i]-'a';
            mat[src][dest] = min(mat[src][dest],cost[i]);
        }

        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    if(mat[i][k]!=inf && mat[k][j]!=inf)
                        mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                }
            }
        }

        ll ans = 0LL;
        int len=source.size();
        for(int i=0;i<len;i++){
            if(source[i]!=target[i]){
                int dist = mat[source[i]-'a'][target[i]-'a'];
                if(dist == inf) return -1;
                ans += dist;
            }
        }

        return ans;
    }
};