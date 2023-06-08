class Node{
    public:
    int key,val,cnt;
    Node *next,*prev;
    Node(int k,int v){
        key=k; val=v; cnt=1; next=NULL; prev=NULL;
    }
};
class List {
    public:
    int size;
    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);
    List() {
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    void addNode(Node* node){
        Node* temp=head->next;
        node->next=temp; node->prev=head;
        head->next=node; temp->prev=node;
        size++;
    }
    void removeNode(Node* node){
        Node* dPrev=node->prev;
        Node* dNext=node->next;
        dPrev->next=dNext; dNext->prev=dPrev;
        node->next=NULL; node->prev=NULL;
        size--;
    }
};
class LFUCache {
public:
     map<int,Node*>keyMap;
     map<int,List*>freqList;
     int maxi,minFreq,curr;
    LFUCache(int capacity) {
        maxi=capacity; minFreq=0; curr=0;
    }
    
    void update(Node* node){
        keyMap.erase(node->key);
        freqList[node->cnt]->removeNode(node);
        if(node->cnt==minFreq && freqList[minFreq]->size==0) minFreq++;
        node->cnt+=1;
        List* newList=new List();
        if(freqList.find(node->cnt)!=freqList.end()) newList=freqList[node->cnt];
        newList->addNode(node);
        freqList[node->cnt]=newList;
        keyMap[node->key]=node;
        return;
    }

    int get(int key) {
        if(keyMap.find(key)!=keyMap.end()){
            Node* node=keyMap[key];
            int val=node->val;
            update(node);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxi==0) return;
        if(keyMap.find(key)!=keyMap.end()){
            Node* node=keyMap[key];
            node->val=value;
            update(node);
        }
        else{
            if(curr==maxi){
                List* newList=freqList[minFreq];
                Node* last=newList->tail->prev;
                keyMap.erase(last->key);
                newList->removeNode(last);
                curr--;
            }
            curr++;
            minFreq=1;
            List* newList=new List();
            if(freqList.find(minFreq)!=freqList.end()) newList=freqList[minFreq];
            Node* newNode=new Node(key,value);
            newList->addNode(newNode);
            freqList[minFreq]=newList;
            keyMap[key]=newNode;
        }
        return;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */