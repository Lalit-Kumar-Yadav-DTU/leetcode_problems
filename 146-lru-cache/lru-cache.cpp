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
        }
    };
    Node *dummyHead = new Node(-1,-1);
    Node *dummyTail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*>mp;

    LRUCache(int capacity) {
        cap = capacity;
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    void insertAfterHead(Node *newNode){
        Node *temp = dummyHead->next;
        newNode->next = temp;
        dummyHead->next = newNode;
        newNode->prev = dummyHead;
        temp->prev = newNode;
    }

    void removeNode(Node *delNode){
        // Node *delNodePrev = delNode->prev;
        // Node *delNodeNext = delNode->next;
        // delNodePrev->next = delNodeNext;
        // delNodeNext->prev = delNodePrev;
        // if(delNode == NULL) return ;
        delNode->next->prev = delNode->prev;
        delNode->prev->next = delNode->next;
        delNode->next = NULL;
        delNode->prev = NULL;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        Node *tempNode = mp[key];
        int res = tempNode->val;
        mp.erase(key);
        removeNode(tempNode);
        insertAfterHead(tempNode);
        mp[key] = dummyHead->next;
        return res;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node *tempNode = mp[key];
            mp.erase(key);
            removeNode(tempNode);
            insertAfterHead(new Node(key,value));
            mp[key] = dummyHead->next;
            return ;
        }
        if(mp.size()<cap){
            insertAfterHead(new Node(key, value));
            mp[key] = dummyHead->next;
        }
        else{
            mp.erase(dummyTail->prev->key);
            removeNode(dummyTail->prev);
            insertAfterHead(new Node(key,value));
            mp[key] = dummyHead->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */