#include <iostream>
using namespace std;

template <typename E>
class SNode {                       // a node in a list of objects
public:
    E elem;                         // element value
    SNode<E> *next;                    // next pointer to the next item in the list
};

template <typename E>
class SLinkedList {
private: 
    SNode<E> *head;                    // pointer to the head of the list
public:
    SLinkedList();                  // empty list constructor
    ~SLinkedList();                 // destructor

    bool empty() const;             // is list empty?
    const E& front() const;         // get front element
    void addFront(const E& e);      // add to front of list
    void removeFront();             // remove front item of the list
};

template <typename E>
SLinkedList<E>::SLinkedList() {
    head = NULL;
}

template <typename E>
SLinkedList<E>::~SLinkedList() {
    while (!empty()) 
        removeFront();
}

template <typename E>
bool SLinkedList<E>::empty() const {
    return head == NULL;
}

template <typename E>
const E& SLinkedList<E>::front() const {
    return head->elem;
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {
    SNode<E> *v = new SNode<E>();
    v->elem = e;
    v->next = head;
    head = v;
}

template <typename E>
void SLinkedList<E>::removeFront() {
    SNode<E> *v = head->next;
    delete head;
    head = v;
}

int main() {
    SLinkedList<string> sll;
    sll.addFront("BOS");
    sll.addFront("ATL");
    sll.addFront("MSP");
    sll.addFront("LAX");

    while (!sll.empty()) {
        cout << sll.front() << " ";
        sll.removeFront();
    }
    return 0;
}
