#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>

template <typename T>
class CircularLinkedList {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* tail; 
    size_t list_size;

    void copy_from(const CircularLinkedList& other) {
        if (other.empty()) return;
        Node* current = other.tail->next;
        do {
            push_back(current->data);
            current = current->next;
        } while (current != other.tail->next);
    }

public:
    CircularLinkedList() : tail(nullptr), list_size(0) {}

    ~CircularLinkedList() {
        clear();
    }

    CircularLinkedList(const CircularLinkedList& other) : tail(nullptr), list_size(0) {
        copy_from(other);
    }

    CircularLinkedList& operator=(const CircularLinkedList& other) {
        if (this != &other) {
            clear();
            copy_from(other);
        }
        return *this;
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            tail = newNode;
            tail->next = tail;
        }
        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        ++list_size;
    }

    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (empty()) {
            tail = newNode;
            tail->next = tail;
        }
        else {
            newNode->next = tail->next; 
            tail->next = newNode;
        }
        ++list_size;
    }

    void insert(size_t idx, const T& value) {
        if (idx > list_size) {
            throw std::out_of_range("Index out of range");
        }
        if (idx == 0) {
            push_front(value);
        }
        else if (idx == list_size) {
            push_back(value);
        }
        else {
            Node* newNode = new Node(value);
            Node* current = tail->next;
            for (size_t i = 0; i < idx - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            ++list_size;
        }
    }

    void pop_back() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        if (list_size == 1) {
            delete tail;
            tail = nullptr;
        }
        else {
            Node* current = tail->next;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = current->next;
        }
        --list_size;
    }

    void pop_front() {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        Node* head = tail->next;
        if (tail == head) {
            delete head;
            tail = nullptr;
        }
        else {
            tail->next = head->next;
            delete head;
        }
            --list_size;
    }

    void remove_at(size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range");
        }
        if (index == 0) {
            pop_front();
        }
        else if (index == list_size - 1) {
            pop_back();
        }
        else {
            Node* current = tail->next;
            for (size_t i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node* to_delete = current->next;
            current->next = to_delete->next;
            delete to_delete;
            --list_size;
        }
    }

    T& operator[](const size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = tail->next;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    T const& operator[](const size_t index) const {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range");
        }
        Node* current = tail->next;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    size_t size() const { return list_size; }

    bool empty() const { return list_size == 0; }

    void clear() {
        while (!empty()) {
            pop_front();
        }
    }

    T front() const {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        return tail->next->data;
    }

    T back() const {
        if (empty()) {
            throw std::underflow_error("List is empty");
        }
        return tail->data;
    }

    void print() const {
        if (empty()) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = tail->next;
        do {
            std::cout << current->data;
            current = current->next;
            if (current != tail->next) {
                std::cout << " -> ";
            }
        } while (current != tail->next);
        std::cout << std::endl;
    }

    void run_commands() {
        std::string command;
        while (true) {
            std::cout << "> ";
            std::getline(std::cin, command);

            if (command == "exit") {
                break;
            }

            std::istringstream iss(command);
            std::string cmd;
            iss >> cmd;

            if (cmd == "push_back") {
                std::string value;
                iss >> value;
                push_back(value);
            }
            else if (cmd == "push_front") {
                std::string value;
                iss >> value;
                push_front(value);
            }
            else if (cmd == "insert") {
                size_t index;
                std::string value;
                iss >> index >> value;
                insert(index, value);
            }
            else if (cmd == "pop_back") {
                try {
                    pop_back();
                }
                catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }
            else if (cmd == "pop_front") {
                try {
                    pop_front();
                }
                catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }
            else if (cmd == "remove_at") {
                size_t index;
                iss >> index;
                try {
                    remove_at(index);
                }
                catch (std::exception& e) {
                        std::cout << e.what() << std::endl;
                }
            }
            else if (cmd == "front") {
                try {
                    std::cout << "Front: " << front() << std::endl;
                }
                catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }
            else if (cmd == "back") {
                try {
                    std::cout << "Back: " << back() << std::endl;
                }
                catch (std::exception& e) {
                    std::cout << e.what() << std::endl;
                }
            }
            else if (cmd == "size") {
                std::cout << "Size: " << size() << std::endl;
            }
            else if (cmd == "empty") {
                std::cout << "Empty: " << std::boolalpha << empty() << std::endl;
            }
            else if (cmd == "print") {
                print();
            }
            else {
                std::cout << "Unknown command!" << std::endl;
            }
        }
    }
};

int main() {
    CircularLinkedList<std::string> list;
    list.run_commands();
    return 0;
}