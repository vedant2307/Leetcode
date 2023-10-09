class MyHashMap {
public:
    vector<int>temp;
    MyHashMap() {
        temp.resize(1e6+1,-1);
    }
    
    void put(int key, int value) {
        temp[key]=value; return;
    }
    
    int get(int key) {
        return temp[key];
    }
    
    void remove(int key) {
        temp[key]=-1; return;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */