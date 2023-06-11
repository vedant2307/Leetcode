class SnapshotArray {
    int size; int cnt;
    map<int,map<int,int>>mp;
public:
    SnapshotArray(int length) {
        cnt=0; 
        for(int i=0;i<length;i++){
            map<int,int>mp1; mp1[0]=0;
            mp[i]=mp1;
        }
    }
    
    void set(int index, int val) {
        mp[index][cnt]=val;
    }
    
    int snap() {
        return cnt++;
    }
    
    int get(int index, int snap_id) {
        auto it=mp[index].upper_bound(snap_id); it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */