class Node{
    public:
    string url;
    Node *prev,*next;
    Node(string url){
        this->url=url;
        prev=NULL;
        next=NULL;
    }
};
class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node *vis=new Node(url);
        curr->next=vis;
        vis->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(steps && curr->prev){
            curr=curr->prev; steps--;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while(steps && curr->next){
            curr=curr->next; steps--;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */