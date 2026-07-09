class LinkedList {
private:
        struct Node {
            int value;
            Node* next;
            Node(int v) : value(v), next(nullptr) {}
        };
        Node* head;
        Node* tail;
        int size;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* curr = head;
        for (int i = 0; i < index ; i++) {
            curr = curr->next;
        }
        return curr->value;
    }

    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if (!tail) tail = head;
        size++;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (!tail) {
            tail = head = newNode;
        }
        tail->next = newNode;
        tail = newNode;
        size++;

    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (!head) tail = nullptr;
            delete temp;
        } else {
            Node* curr = head;
            for (int i=0; i < index-1; i++) {
                curr = curr->next;
            }
            Node* toDelete = curr->next;
            curr->next = toDelete->next;
            if (toDelete == tail) tail = curr;
            delete toDelete;
        }
        size--;
        return true;

    }

    vector<int> getValues() {
        std::vector<int> res;
        Node* curr = head;
        while (curr) {
            res.push_back(curr->value);
            curr = curr->next;
        }
        return res;
    }
};
