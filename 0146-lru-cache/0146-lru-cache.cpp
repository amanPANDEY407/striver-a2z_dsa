struct Node{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int x, int y){
        key = x;
        value = y;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int,Node*> mpp;
    Node *head;
    Node *tail;
    int cap;

    void removeNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addBeforeHead(Node* node){
        node->next = head;
        node->prev = head->prev;
        head->prev->next = node;
        head->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        tail = new Node(-1,-1);
        head = new Node(-1,-1);
        tail->next = head;
        head->prev = tail;
    }

    int get(int key) {
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        Node* x = mpp[key];
        removeNode(x);
        addBeforeHead(x);
        return x->value;
    }

    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* existing = mpp[key];
            existing->value = value;
            removeNode(existing);
            addBeforeHead(existing);
            return;
        }

        if(mpp.size() == cap){
            Node* z = tail->next;
            int zz = z->key;
            removeNode(z);
            delete z;
            mpp.erase(zz);
        }

        Node* y = new Node(key,value);
        addBeforeHead(y);
        mpp[key] = y;
    }
};