// Insert a node at  specific position in a linked list.

#include <iostream>
using namespace std;

// Node definition
class Node {
public:
    int val;
    Node *next;

    Node(int x) {
        val = x;
        next = nullptr;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);

    Node* curr = head;

    // -------- Display original list --------
    cout << "Original List: ";
    curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    // -------- Take input for insertion --------
    int pos, val;
    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;

    // -------- Insert at position --------
    if (pos == 1) {
        // insert at head
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    } else {
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Position is greater than list length!" << endl;
        }
    }

    // -------- Display updated list --------
    cout << "Updated List: ";
    curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}