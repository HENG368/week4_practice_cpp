// helpdesk ticket queue implemented with singly linked list
#include<iostream>
#include<string>

// We avoid 'using namespace std;' in a header to prevent polluting including translation units.

// Node structure holding an ID and a name
template<typename T1, typename T2>
struct Node {
    T1 id;
    T2 name;
    Node<T1, T2>* next;
    Node(const T1& id_, const T2& name_) : id(id_), name(name_), next(nullptr) {}
};    

// Queue class template - now with TWO template parameters to match Node
template<typename T1, typename T2>    
class queue {
private:
    Node<T1, T2>* head; // front
    Node<T1, T2>* tail; // back

public:
    queue() : head(nullptr), tail(nullptr) {}

    // Check if queue is empty (no arguments needed because we store head/tail as members)
    bool isempty() const {
        return head == nullptr; // if head is null, tail should also be null
    }

    // Enqueue (push at back)
    void push(const T1& id, const T2& name) {
        Node<T1, T2>* newNode = new Node<T1, T2>(id, name);
        if (isempty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Dequeue (pop from front)
    void pop() {
        if (isempty()) {
            std::cout << "Queue empty, nothing to dequeue.\n";
            return;
        }
        Node<T1, T2>* tmp = head;
        head = head->next;
        if (head == nullptr) tail = nullptr; // became empty
        delete tmp;
    }

    // Peek at front element
    Node<T1, T2>* front() const { return head; }

    // Display all elements
    void display() const {
        if (isempty()) {
            std::cout << "(empty)\n";
            return;
        }
        Node<T1, T2>* cur = head;
        while (cur) {
            std::cout << "ID: " << cur->id << ", Name: " << cur->name << "\n";
            cur = cur->next;
        }
    }

    // // Destructor to free nodes
    // ~queue() {
    //     while (!isempty()) {
    //         dequeue();
    //     }
    // }
};