class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int k, int v){
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };

    Node *head, *tail;
    int cap;
    unordered_map<int, Node*>mp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addNodeAfterHead(Node *node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node *delNode){
        delNode->next->prev = delNode->prev;
        delNode->prev->next = delNode->next;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node* node = mp[key];
        removeNode(node);
        addNodeAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            removeNode(node);
            addNodeAfterHead(node);
        }
        else{
            if(mp.size() == cap) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            addNodeAfterHead(newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */