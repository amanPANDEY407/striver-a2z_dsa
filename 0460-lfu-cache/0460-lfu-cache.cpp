struct Node{
    int key;
    int value;
    int cnt;
    Node *prev;
    Node *next;
    Node(int x, int y){
        key = x;
        value = y;
        cnt = 1;
        prev = nullptr;
        next = nullptr;
    }
};
struct List {
    int size;
    Node* head;
    Node* tail;

    List() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        size++;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
};
class LFUCache {
private:
    int cap;
    int minf;
    int size;
    unordered_map<int,Node*> knm;
    unordered_map<int,List*> fnm;
public:
    LFUCache(int capacity) {
        cap = capacity;
        minf = 0;
        size = 0;
    }
    void updFL(Node* node){
        fnm[node->cnt]->removeNode(node);
        if(node->cnt == minf && fnm[node->cnt]->size == 0){
           minf++;
        }
        node->cnt++;
        if(fnm.find(node->cnt) == fnm.end()){
           fnm[node->cnt] = new List();
        }
        fnm[node->cnt]->addNode(node);
    }
    
    int get(int key) {
        if (knm.find(key) == knm.end()){
           return -1;
        }
        Node* node = knm[key];
        updFL(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cap == 0){
            return;
        }
        if(knm.find(key) != knm.end()){
            Node* node = knm[key];
            node->value = value;
            updFL(node);
            return;
        }
        if(size == cap){
            List* minFreqList = fnm[minf];
            Node* lruNode = minFreqList->tail->prev;

            knm.erase(lruNode->key);
            minFreqList->removeNode(lruNode);
            delete lruNode;
            size--;
        }
        size++;
        minf = 1;

        List* listFreq1;
        if(fnm.find(minf) != fnm.end()){
            listFreq1 = fnm[minf];
        }else{
            listFreq1 = new List();
            fnm[minf] = listFreq1;
        }

        Node* newNode = new Node(key, value);
        listFreq1->addNode(newNode);
        knm[key] = newNode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */