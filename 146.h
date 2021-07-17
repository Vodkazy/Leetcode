struct LRU{
    int k, v;
    LRU* pre;
    LRU* next;
    LRU(): k(0), v(0), pre(nullptr), next(nullptr) {}
    LRU(int _key, int _value): k(_key), v(_value), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int size;
    int cap;
    map<int, LRU*> cache;
    LRU* head; //dummy head
    LRU* tail; //dummy tail

    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = new LRU();
        tail = new LRU();
        head->next = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if(cache.count(key)==0)return -1;
        else{
        // 如果 key 存在，先通过哈希表定位，再移到头部
        LRU* node = cache[key];
        moveToHead(node);
        return node->v;
        }
    }
    
    void put(int key, int value) {
        if(cache.count(key)>0){
            LRU* node = cache[key];
            node->v = value;
            moveToHead(node);
        }else{
            if(size+1>cap){
                LRU* node = tail->pre;
                cache.erase(node->k);
                removeTail();
                size--;
            }
            LRU* new_node = new LRU(key, value);
            cache[key] = new_node;
            addNewNodeToHead(new_node);
            size++;
        }
        // for(auto iter=cache.begin();iter!=cache.end();iter++){
        //     cout<<*iter->first<<" "<<*iter->second->v<<endl;
        // }
    }

    void addNewNodeToHead(LRU* node){
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }

    void removeTail(){
        LRU* node = tail->pre;
        node->pre->next = tail;
        tail->pre = node->pre;
    }

    void moveToHead(LRU* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
// 双向链表作为维护的数据结构，map作为索引。
// 每次把当前访问的单元放到双向链表的最前端，每次操作同时维护map和双向链表即可。 
//    int size;
//    int cap;
//    map<int, LRU*> cache;
//    LRU* head; //dummy head
//    LRU* tail; //dummy tail 
