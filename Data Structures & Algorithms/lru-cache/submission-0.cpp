class LRUCache {
public:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : 
            key(k), val(v), 
            prev(NULL), next(NULL){}
    };
    
    int cap;
    unordered_map<int, Node*>mp;
    Node* head;
    Node* tail;

    void addtofront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removenode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* node = mp[key];
        removenode(node);
        addtofront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) !=mp.end()){
            Node* node = mp[key];
            node->val = value;
            removenode(node);
            addtofront(node);
            return;
        }

        //FULL MEMEORY.
        if(mp.size() == cap){
            Node* lru = tail->prev;
            removenode(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* newnode = new Node(key,value);
        addtofront(newnode);
        mp[key] = newnode;
    }
};
