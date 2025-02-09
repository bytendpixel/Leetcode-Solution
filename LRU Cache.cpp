// Define the Node structure to hold all necessary information for each key
struct Node {
    int value;   // Value associated with the key
    int next;    // Next key in the linked list
    int prev;    // Previous key in the linked list
    bool exists; // Flag to indicate if the key is present in the cache

    // Constructor to initialize a Node
    Node() : value(-1), next(-1), prev(-1), exists(false) {}
};

class LRUCache {
public:
    // Array of Nodes, one for each possible key
    Node nodes[10001];

    int capacity;      // Maximum capacity of the cache
    int head;          // Most recently used key
    int tail;          // Least recently used key
    int current_size;  // Current number of keys in the cache

    // Constructor to initialize the cache with given capacity
    LRUCache(int capacity_) {
        capacity = capacity_;
        head = -1;
        tail = -1;
        current_size = 0;
        // No need to explicitly initialize nodes as the Node constructor handles it
    }

    // Function to get the value of the key if it exists, else return -1
    int get(int key) {
        if (!nodes[key].exists) return -1; // Key not present
        promote(key);                      // Move key to the front (MRU)
        return nodes[key].value;
    }

    // Function to put a key-value pair into the cache
    void put(int key, int value) {
        if (nodes[key].exists) {
            nodes[key].value = value; // Update the value
            promote(key);            // Move key to the front (MRU)
        }
        else {
            // Insert new key
            nodes[key].value = value;
            nodes[key].exists = true;
            nodes[key].prev = -1;
            nodes[key].next = head;

            if (head != -1) {
                nodes[head].prev = key;
            }
            head = key;

            // If cache was empty, set tail to the new key
            if (tail == -1) {
                tail = key;
            }

            current_size++;

            // If capacity exceeded, evict the least recently used key
            if (current_size > capacity) {
                evict();
            }
        }
    }

private:
    // Function to evict the least recently used key (tail)
    void evict(){
        if (tail == -1) return; // Nothing to evict

        int key_to_remove = tail;
        nodes[key_to_remove].exists = false;

        int newTail = nodes[tail].prev;
        if (newTail != -1){
            nodes[newTail].next = -1;
        }
        tail = newTail;
        current_size--;
    }

    // Function to promote a key to the front (head) of the linked list
    void promote(int key){
        if (head == key) return; // Already at the front

        int prevKey = nodes[key].prev;
        int nextKey = nodes[key].next;

        // If the key is at the tail, update the tail
        if (tail == key){
            tail = prevKey;
        }

        // Remove the key from its current position
        if (prevKey != -1){
            nodes[prevKey].next = nextKey;
        }
        if (nextKey != -1){
            nodes[nextKey].prev = prevKey;
        }

        // Insert the key at the front
        nodes[key].prev = -1;
        nodes[key].next = head;
        if (head != -1){
            nodes[head].prev = key;
        }
        head = key;
    }
};
