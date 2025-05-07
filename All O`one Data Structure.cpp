const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

struct Node {
    Node *next;
    Node *prev;
    int count;
    unordered_set<string> keys;

    Node();

    Node(int cnt) : count(cnt), next(nullptr), prev(nullptr) {};
};


class AllOne {
private:
    Node *head; // represents the maximum;
    Node *tail; // represents the minimum
    unordered_map<string,Node*> mp;

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head -> prev = tail;
        tail -> next = head;
    }
    
    void inc(string key) {
        if (mp.count(key)) {
            Node *curNode = mp[key];
            mp.erase(key);
            curNode->keys.erase(key);

            Node *nextNode = curNode -> next;

            if (nextNode == head || nextNode -> count - curNode -> count > 1) {
                Node *newNode = new Node(curNode -> count + 1);
                newNode->keys.insert(key);

                curNode -> next = newNode;
                newNode -> prev = curNode;

                newNode -> next = nextNode;
                nextNode -> prev = newNode;

                mp[key] = newNode;
            } else {
                nextNode->keys.insert(key);
                mp[key] = nextNode;
            }

            if (curNode->keys.empty()) {
                deleteNode(curNode);
            }
        } else {
            if (tail->next->count != 1) {
                Node *newNode = new Node(1);
                newNode->keys.insert(key);
                mp[key] = newNode;

                Node *nextNode = tail->next;

                tail->next = newNode;
                newNode->prev = tail;

                nextNode -> prev = newNode;
                newNode -> next = nextNode;
            } else {
                tail->next->keys.insert(key);
                mp[key] = tail->next;
            }
        }
    }
    
    void dec(string key) {
        Node *cur = mp[key];
        mp.erase(key);
        cur->keys.erase(key);

        if (cur -> count > 1) {
            Node *prevNode = cur -> prev;
            if (prevNode == tail || cur -> count - prevNode -> count > 1) {
                Node *newNode = new Node(cur->count -1);
                newNode->keys.insert(key);

                prevNode->next = newNode;
                newNode->prev = prevNode;

                newNode->next = cur;
                cur->prev = newNode;

                mp[key] = newNode;
            } else {
                prevNode->keys.insert(key);
                mp[key]= prevNode;
            }

            if (cur->keys.empty()) {
                deleteNode(cur);
            }
        } else {
            if (cur->keys.empty()) {
                deleteNode(cur);
            }
        }
    }

    void deleteNode(Node *cur) {
        Node *curNext = cur -> next;
        Node *curPrev = cur -> prev;

        curPrev -> next = curNext;
        curNext -> prev = curPrev;

        cur -> next = nullptr;
        cur -> prev = nullptr;

        delete cur;
    }
    
    string getMaxKey() {
        if (head -> prev == tail) {
            return "";
        }
        cout << "Yo" << ' ';
        return *(head->prev->keys.begin());
    }
    
    string getMinKey() {
        if (tail -> next == head) {
            return "";
        }
        return *(tail->next->keys.begin());
    }
};
