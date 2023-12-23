class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0,y=0;
        map<pair<int,int>,int>mp;
        mp[{x,y}]++;
        for(auto it:path){
            if(it=='N') y+=1;
            else if(it=='S') y-=1;
            else if(it=='E') x+=1;
            else x-=1;
            mp[{x,y}]++;
            if(mp[{x,y}]>1) return true;
        }
        return false;
    }
};