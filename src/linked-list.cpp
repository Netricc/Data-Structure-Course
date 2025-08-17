#include <iostream>
using namespace std;

template <class T>
class linkedList {
    struct Node {
        T data;
        Node* next;
    };

    Node* first;
    Node* last;
    int length;

public:
    linkedList() {
        first = last = nullptr;
        length = 0;
    }

    bool isEmpty() {
        return length == 0;
    }

    void insertFirst(T element) {
        Node* newNode = new Node;
        newNode->data = element;
        if (isEmpty()) {
            first = last = newNode;
            newNode->next = nullptr;
        } else {
            newNode->next = first;
            first = newNode;
        }
        length++;
    }

    void insertLast(T element) {
        Node* newNode = new Node;
        newNode->data = element;
        newNode->next = nullptr;
        if (isEmpty()) {
            first = last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    void insertByPosition(T element, int pos) {
        if (pos < 0 || pos > length) {
            cout << "Position Out Of Range" << endl;
        } else if (pos == 0) {
            insertFirst(element);
        } else if (pos == length) {
            insertLast(element);
        } else {
            Node* newNode = new Node;
            newNode->data = element;
            Node* cur = first;
            for (int i = 1; i < pos; i++) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            length++;
        }
    }

    void display() {
        Node* cur = first;
        while (cur != nullptr) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    void removeFirst() {
        if (isEmpty()) {
            cout << "Empty List can't remove" << endl;
            return;
        }

        Node* temp = first;
        first = first->next;
        delete temp;
        length--;

        if (length == 0)
            last = nullptr;
    }

    void removeLast() {
        if (isEmpty()) {
            cout << "Empty List can't remove" << endl;
            return;
        }

        if (length == 1) {
            delete first;
            first = last = nullptr;
        } else {
            Node* prev = first;
            while (prev->next != last) {
                prev = prev->next;
            }
            delete last;
            last = prev;
            last->next = nullptr;
        }
        length--;
    }

    void remove(T element) {
        if (isEmpty()) return;

        if (first->data == element) {
            removeFirst();
            return;
        }

        Node* curr = first->next;
        Node* prev = first;

        while (curr != nullptr && curr->data != element) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Element (" << element << ") was not found" << endl;
        } else {
            prev->next = curr->next;
            if (curr == last)
                last = prev;
            delete curr;
            length--;
        }
    }
};

int main() {
    linkedList<int> s;

    s.insertLast(1);
    s.insertLast(2);
    s.insertLast(3);
    s.insertLast(3);
    s.insertLast(4);
    s.insertLast(5);

    s.display();

    s.remove(3); // removes first occurrence of 3

    s.display();

    return 0;
}
