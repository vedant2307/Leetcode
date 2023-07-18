
class LRUCache {
    class ListNode{
        public:
        int key,val;
        ListNode *next,*prev;
        ListNode(int k,int v){
            key=k; val=v; next=NULL; prev=NULL;
        }
    };
    ListNode *head=new ListNode(-1,-1);
    ListNode *tail=new ListNode(-1,-1);
    unordered_map<int,ListNode*>mp;
    int maxi;

    void addNode(ListNode* node){
        ListNode* temp=head->next;
        mp[node->key]=node;
        node->next=temp; node->prev=head;
        head->next=node; temp->prev=node;
    }
    void deleteNode(ListNode* node){
        mp.erase(node->key);
        ListNode* dPrev=node->prev;
        ListNode* dNext=node->next;
        dPrev->next=dNext; dNext->prev=dPrev;
        node->next=NULL; node->prev=NULL;
    }

public:

    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        maxi=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            ListNode* node=mp[key];
            //mp.erase(key);
            deleteNode(node);
            addNode(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        ListNode* newNode=new ListNode(key,value);
        if(mp.find(key)!=mp.end()){
            ListNode* node=mp[key];
            deleteNode(node);
        }
        if(mp.size()==maxi){
            deleteNode(tail->prev);
        }
        addNode(newNode);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */