#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int d) {
        Node* newNode = new Node(d);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    class iterator {
    public:
        Node* ptr;

        iterator(Node* p) {
            ptr = p;
        }

        int& operator*() {
            return ptr->data;
        }

        iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }

        bool operator!=(const iterator& other) const {
            return ptr != other.ptr;
        }
    };

    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(nullptr);
    }
};

int main() {
    LinkedList list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    cout << "List contents: ";
    for (int element : list) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}

