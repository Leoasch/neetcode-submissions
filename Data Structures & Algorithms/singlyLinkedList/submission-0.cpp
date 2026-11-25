#include <vector>

class ListNode {
public:
    ListNode* next = nullptr;
    int value;

    ListNode(int value) {
        this->value = value;
    }
};

class LinkedList {
private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    void destroyNodes () {
        ListNode* current = head;
        ListNode* previous;
        while (current) {
            previous = current;
            current = getNext(current);
            delete previous;
        }
        head = nullptr;
        tail = nullptr;
    }

    ListNode* getNext (ListNode* node) const {
        return node->next;  
    }

public:
    LinkedList() {}

    LinkedList(const LinkedList& other) {
        for (int value : other.getValues()) {
            insertTail(value);
        }
    }

    LinkedList& operator=(const LinkedList& other) {
        if (this == &other) {
            return *this;
        }
        destroyNodes();

        for (int value : other.getValues()) {
            insertTail(value);
        }

        return *this;
    }

    ~LinkedList () {
        destroyNodes();
    }


    int get(int position) const {
        ListNode* current = head;

        for (int i = 0; i < position && current; i++) {
            current = getNext(current);
        }

        if (!current || position < 0) { return -1; }
        return current->value;
    }

    void insertHead(int val) {
        ListNode* newNode = new ListNode(val);
        if (head) {
            newNode->next = head;
        } else {
            tail = newNode;
        }
        head = newNode;
    }
    
    void insertTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (tail) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    bool remove(int position) {
        ListNode* current = head;
        ListNode* previous = nullptr;

        for (int i = 0; i < position && current; i++) {
            previous = current;
            current = getNext(current);
        }

        if (!current || position < 0) {
            return false;
        }
        if (previous) {
            previous->next = current->next;
        }
        if (current == head) {
            head = current->next;
        } 
        if (current == tail) {
            tail = previous;
        }
        delete current;
        return true;
    }

    std::vector<int> getValues() const {
        ListNode* current = head;
        std::vector<int> values;
        while (current) {
            values.push_back(current->value);
            current = getNext(current);
        }
        return values;
    }
};
