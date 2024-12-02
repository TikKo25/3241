#include <iostream>
#include <stdexcept>

template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    struct SentinelNode {
        Node* next; 
    };

    SentinelNode* sentinel; 
    Node* tail;             
    size_t count;          

public:
    CircularLinkedList() : sentinel(new SentinelNode()), tail(nullptr), count(0) {
        sentinel->next = sentinel; 
    }

    ~CircularLinkedList() {
        clear();
        delete sentinel; 
    }

    CircularLinkedList(const CircularLinkedList& other) : sentinel(new SentinelNode()), tail(nullptr), count(0) {
        Node* current = other.sentinel->next; 
        while (current != other.sentinel) {
            push_back(current->data); 
            current = current->next;
        }
    }

    CircularLinkedList& operator=(const CircularLinkedList& other) {
        if (this != &other) {
            clear();
            delete sentinel;
            sentinel = new SentinelNode();
            tail = nullptr;
            count = 0;

            Node* current = other.sentinel->next; 
            while (current != other.sentinel) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            sentinel->next = newNode;
            newNode->next = sentinel; 
        }
        else {
            tail->next = newNode; 
            newNode->next = sentinel;
        }
        tail = newNode; 
        ++count; 
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            sentinel->next = newNode; 
            newNode->next = sentinel; 
            tail = newNode; 
        }
        else {
            newNode->next = sentinel->next; 
            sentinel->next = newNode; 
        }
        ++count;
    }

    void insert(size_t idx, const T& value) {
        if (idx > count) {
            throw std::out_of_range("Index out of range");
        }
        if (idx == 0) {
            push_front(value);
        }
        else if (idx == count) {
            push_back(value);
        }
        else {
            Node* newNode = new Node(value);
            Node* current = sentinel; 
                for (size_t i = 0; i < idx; ++i) {
                    current = current->next;
                }
            newNode->next = current->next;
            current->next = newNode;
            ++count;
        }
    }

    void pop_back() {
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        if (count == 1) {
            delete sentinel->next; 
            sentinel->next = sentinel; 
            tail = nullptr;
        }
        else {
            Node* current = sentinel;
            while (current->next != tail) {
                current = current->next; 
            }
            delete tail;
            tail = current; 
            tail->next = sentinel; 
        }
        --count;
    }

    void pop_front() {
        if (empty()) {
                throw std::runtime_error("List is empty");
            }
            if (count == 1) {
                delete sentinel->next;
                sentinel->next = sentinel;
                tail = sentinel;
            }
            else {
                Node* current = sentinel;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = sentinel;
            }
            --count;
        }

        void pop_front() {
            if (empty()) {
                throw std::runtime_error("List is empty");
            }
            Node* first = sentinel->next;
            if (count == 1) {
                delete first;
                sentinel->next = sentinel;
                tail = sentinel;
            }
            else {
                sentinel->next = first->next;
                delete first;
            }
            --count;
        }

        void remove_at(size_t index) {
            if (index >= count) {
                throw std::out_of_range("Index out of range");
            }
            if (index == 0) {
                pop_front();
            }
            else if (index == count - 1) {
                pop_back();
            }
            else {
                Node* current = sentinel;
                for (size_t i = 0; i < index; ++i) {
                    current = current->next;
                }
                Node* toDelete = current->next;
                current->next = toDelete->next;
                delete toDelete;
                --count;
            }
        }

        T& operator[](const size_t index) {
            if (index >= count) {
                throw std::out_of_range("Index out of range");
            }
            Node* current = sentinel->next;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->data;
        }

        const T& operator[](const size_t index) const {
            if (index >= count) {
                throw std::out_of_range("Index out of range");
            }
            Node* current = sentinel->next;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->data;
        }

        size_t size() const {
            return count;
        }

        bool empty() const {
            return count == 0;
        }

        void clear() {
            while (!empty()) {
                pop_front();
            }
        }

        T front() const {
            if (empty()) {
                throw std::runtime_error("List is empty");
            }
            return sentinel->next->data;
        }

        T back() const {
            if (empty()) {
                throw std::runtime_error("List is empty");
            }
            return tail->data;
        }

        void print() const {
            if (empty()) {
                std::cout << "List is empty" << std::endl;
                return;
            }
            Node* current = sentinel->next;
            do {
                std::cout << current->data << " -> ";
                current = current->next;
            } while (current != sentinel->next);
            std::cout << "(head)" << std::endl;
        }
    };

