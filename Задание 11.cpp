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

    Node* P;
    size_t count;

public:
    CircularLinkedList() : P(nullptr), count(0) {}
    ~CircularLinkedList() {
        clear();
    }

    CircularLinkedList(const CircularLinkedList& other) : P(nullptr), count(0) {
        Node* current = other.P;
        if (current) {
            do {
                push_back(current->data); 
                current = current->next;
            } while (current != other.P);
        }
    }

    CircularLinkedList& operator=(const CircularLinkedList& other) {
        if (this != &other) {
            clear();
            Node* current = other.P;
            if (current) {
                do {
                    push_back(current->data);
                    current = current->next;
                } while (current != other.P);
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            P = newNode;
            newNode->next = newNode; 
        }
        else {
            Node* tail = P;
            while (tail->next != P) {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = P; 
        }
        ++count;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            P = newNode; 
            newNode->next = newNode; 
        }
        else {
            newNode->next = P; 
            Node* tail = P;
            while (tail->next != P) {
                tail = tail->next; 
            }
            tail->next = newNode; 
            P = newNode; 
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
            Node* current = P;
            for (size_t i = 0; i < idx - 1; ++i) {
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
            delete P;
            P = nullptr; 
        }
        else {
            Node* tail = P;
            Node* prev = nullptr;
            while (tail->next != P) {
                prev = tail;
                tail = tail->next; 
            }
            delete tail; 
            prev->next = P; 
        }
        --count; 
    }

    void pop_front() {
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        if (count == 1) { 
            delete P; 
            P = nullptr; 
        }
        else {
            Node* newHead = P; 
            while (newHead->next != P) {
                newHead = newHead->next; 
            }
            newHead->next = P->next; 
            delete P; 
            P = newHead->next;
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
            Node* current = P;
            for (size_t i = 0; i < index - 1; ++i) {
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
        Node* current = P;
        for (size_t i = 0; i <= index; ++i) {
            current = current->next; 
        }
        return current->data; 
    }

    const T& operator[](const size_t index) const {
        if (index >= count) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = P;
        for (size_t i = 0; i <= index; ++i) {
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
        return P->data; 
    }

    T back() const {
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        Node* current = P;
        while (current->next != P) {
            current = current->next; 
        }
            return current->data; 
    }
    void print() const {
        if (empty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* current = P;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != P);
        std::cout << "(head)" << std::endl; 
    }
};

