#include <iostream>
#include <stdexcept>
#include <string>

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

    CircularLinkedList() : P(new Node(T())), list_size(0) {
        P->next = P;
    }

    ~CircularLinkedList() {
        clear();
        delete P;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (list_size == 0) {
            P->next = newNode;
            newNode->next = P;
        else {
            Node* last = P;
            while (last->next != P) {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = P;
        }
        ++list_size;
        }

        void push_front(const T & value) {
            Node* newNode = new Node(value);
            if (list_size == 0) {
                P->next = newNode;
                newNode->next = P;
            }
            else {
                newNode->next = P->next;
                P->next = newNode;
            }
            ++list_size;
        }
        void insert(size_t idx, const T & value) {
            if (idx > list_size) {
                throw std::out_of_range("Index out of range");
            }
            if (idx == 0) {
                push_front(value);
                return;
            }
            Node* newNode = new Node(value);
            Node* current = P;
            for (size_t i = 0; i < idx; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            if (newNode->next == P) {
                P->next = newNode;
            }
            ++list_size;
        }

        void pop_back() {
            if (list_size == 0) {
                throw std::out_of_range("List is empty");
            }
            if (list_size == 1) {
                delete P->next;
                P->next = P;
            }
            else {
                Node* current = P;
                while (current->next->next != P) {
                    current = current->next;
                }
                delete current->next;
                current->next = P;
            }
            --list_size;
        }
        void pop_front() {
            if (list_size == 0) {
                throw std::out_of_range("List is empty");
            }
            Node* first = P->next;
            if (first == P) {
                delete first;
                P->next = P;
            }
            else {

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
            Node* current = P;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            Node* nodeToRemove = current->next;
            current->next = nodeToRemove->next;
            if (nodeToRemove == P) {
                P->next = current;
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
            Node* current = P->next; à
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
            Node* current = P->next;
            do {
                std::cout << current->data << " -> ";
                current = current->next;
            } while (current != P->next);
            std::cout << "(head)" << std::endl;
        }
    };
};

