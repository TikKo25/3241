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

    Node* head;
    Node* tail;
    size_t count;

public:
    CircularLinkedList() : head(new Node(T())), tail(head), count(0) {
        head->next = head;
    }

    ~CircularLinkedList() {
        clear();
        delete head;
    }

    CircularLinkedList(const CircularLinkedList& other) : head(new Node(T())), tail(head), count(0) {
        Node* current = other.head->next;
        while (current != other.head) {
            push_back(current->data);
            current = current->next;
        }
    }

    CircularLinkedList& operator=(const CircularLinkedList& other) {
        if (this != &other) {
            clear();
            delete head;
            head = new Node(T());
            tail = head;
            count = 0;

            Node* current = other.head->next;
            while (current != other.head) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head->next = newNode;
            newNode->next = head;
        }
        else {
            tail->next = newNode;
            newNode->next = head;
        }
        tail = newNode;
        ++count;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            head->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
        else {
            newNode->next = head->next;
            head->next = newNode;
            ++count;
        }

        void insert(size_t idx, const T & value) {
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
                Node* current = head;
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
                delete head->next;
                head->next = head;
                tail = head;
            }
            else {
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = head;
            }
            --count;
        }

        void pop_front() {
            if (empty()) {
                throw std::runtime_error("List is empty");
            }
            Node* first = head->next;
            if (count == 1) {
                delete first;
                head->next = head;
                tail = head;
            }
            else {
                head->next = first->next;
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
                Node* current = head;
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
            Node* current = head->next;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            return current->data;
        }

        const T& operator[](const size_t index) const {
            if (index >= count) {
                throw std::out_of_range("Index out of range");
            }
            Node* current = head->next;
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
            return head->next->data;
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
            Node* current = head->next;
            do {
                std::cout << current->data << " -> ";
                current = current->next;
            } while (current != head->next);
            std::cout << "(head)" << std::endl;
        }
    };
};