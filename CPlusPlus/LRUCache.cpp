struct DListNode
{
    DListNode* next;
    DListNode* pre;
    int key;
    int value;
};

class DLinkList {
public:
    DLinkList(){
        tail = NULL;
        head = NULL;
    }
    ~DLinkList() {
        while (head != NULL)
        {
            removeNode(head);
        }
    }
    void moveToHead(DListNode* node)
    {
        if (node == head)
            return;
        if(node == tail)
        {
            tail = node->pre;
            node->next = head;
            node->pre = NULL;
            head->pre = node;
            head = node;
            return;
        }

        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->next = head;
        node->pre = NULL;
        head->pre = node;
        head = node;    
    }
    
    void removeNode(DListNode* node)
    {
        if (!node)
            return;
        if (node != head && node != tail)
        {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        else if (node == tail && node == head)
        {
            tail = head = NULL;
        }
        else if (node == tail)
        {
            node->pre->next = NULL;
            tail = node->pre;
        }
        else
        {
            head = node->next;
            node->next->pre = NULL;
        }
        delete node;
        node = NULL;
    }
    
    void addToHead(DListNode* node)
    {
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            head->pre = node;
            node->next = head;
            head = node;    
        }
    }
    
    int popTailNode()
    {
        int key = tail->key;
        removeNode(tail);
        return key;
    }
    
    DListNode* head;
    DListNode* tail;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        maxNum = capacity;
        currNum = 0;
    }
    ~LRUCache() {
        
    }
    
    int get(int key) {
        if(m_hash.find(key) == m_hash.end())
        {
            return -1;
        }
        DListNode *node = m_hash[key];
        dLinkList.moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        
        if(m_hash.find(key) == m_hash.end())
        {
            DListNode *node = new DListNode;
            node->value = value;
            node->key = key;
            dLinkList.addToHead(node);
            m_hash[key] = node;
            currNum++;
        }
        else
        {
            DListNode* node = m_hash[key];
            node->value = value;
            node->key = key;
            dLinkList.moveToHead(node);
        }
        if (currNum > maxNum)
        {
            int eKey = dLinkList.popTailNode();
            m_hash.erase(eKey);
            currNum--;
        }
    }
    int maxNum;
    int currNum;
    unorder_map<int, DListNode*> m_hash;
    DLinkList dLinkList;
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */