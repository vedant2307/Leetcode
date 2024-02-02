class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int curr=1;
        while(memory1-curr>=0 || memory2-curr>=0){
            if(memory1>=memory2) memory1-=curr;
            else memory2-=curr;
            curr++;
        }
        return {curr,memory1,memory2};
    }
};