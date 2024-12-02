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
    size_t list_size; 

public:
    CircularLinkedList() : P(nullptr), list_size(0) {}
    ~CircularLinkedList() {
        clear();
    }
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (list_size == 0) {
            P = newNode; 
            newNode->next = P; 
        }
        else {
            newNode->next = P->next;
            P->next = newNode; 
        }
        P = newNode; 
        ++list_size;
    }
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (list_size == 0) {
            P = newNode; 
            newNode->next = P; 
        }
        else {
            newNode->next = P->next; 
            P->next = newNode; 
        }
        ++list_size;
    }
    void insert(size_t idx, const T& value) {
        if (idx > list_size) {
            throw std::out_of_range("Index out of range");
        }
        if (idx == 0) {
            push_front(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* current = P->next;
        for (size_t i = 0; i < idx - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode; 
        if (current == P) { 
            P = newNode; 
        }
        ++list_size;
    }
    void pop_back() {
        if (list_size == 0) {
            throw std::out_of_range("List is empty");
        }

        if (list_size == 1) { 
            delete P; 
            P = nullptr;
        }
        else {
            Node* current = P->next;
            while (current->next != P) { 
                current = current->next;
            }
            delete P;
            current->next = P->next; 
            P = current;
        }
        --list_size;
    }
    void pop_front() {
        if (list_size == 0) {
            throw std::out_of_range("List is empty");
        }

        if (list_size == 1) { 
            delete P; 
            P = nullptr; 
        }
        else {
                Node * first = P->next; 
            P->next = first->next;
            delete first;
        }
        --list_size;
    }

    void remove_at(size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            pop_front();
            return;
        }
        Node* current = P->next;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next; 
        }
        Node* nodeToRemove = current->next; 
        current->next = nodeToRemove->next;
        if (nodeToRemove == P) { 
            P = current; 
        }
        delete nodeToRemove;
        --list_size;
    }
    T& operator[](size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = P->next; 
        for (size_t i = 0; i < index; ++i) {
            current = current->next; 
        }
        return current->data; 
    }
    T const& operator[](size_t index) const {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = P->next;
        for (size_t i = 0; i < index; ++i) {
            current = current->next; 
        }
        return current->data;
    }
    size_t size() const {
        return list_size;
    }
    bool empty() const {
        return list_size == 0;
    }
    void clear() {
        while (!empty()) {
            pop_front(); 
        }
    }
    T front() const {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return P->next->data; 
    }
    T back() const {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return P->data; 
    }
    void print() const {
        if (empty()) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* current = P->next;
        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != P->next); 
        std::cout << "(head)" << std::endl; 
    }
};
    int main() {
        CircularLinkedList<std::string> list;
        list.push_back("a");
        list.push_back("b");
        list.push_back("c");
        list.push_back("d");
        list.push_back("e");

        list.print();

        list.push_front("z");
        list.print();

        list.insert(2, "x");
        list.print();

        list.pop_back();
        list.print();

        list.pop_front();
        list.print(); 

        list.remove_at(2);
        list.print(); 
       
            std::cout << "First element: " << list.front() << std::endl;
        std::cout << "Last element: " << list.back() << std::endl;  

        list.clear();
        std::cout << "List cleared. Is empty: " << std::boolalpha << list.empty() << std::endl;
        return 0;
    };