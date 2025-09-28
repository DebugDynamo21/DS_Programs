// Insert a node at a specific position in a linked list. Take input from user.

#include <iostream>
using namespace std;

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
    int n;
    cout << "Enter number of nodes in initial linked list: ";
    cin >> n;

    if (n <= 0) {
        cout << "List cannot be empty!" << endl;
        return 0;
    }

    // -------- Create linked list from user input --------
    cout << "Enter " << n << " values: ";
    int x;
    cin >> x;
    Node *head = new Node(x);   // first node
    Node *curr = head;

    for (int i = 2; i <= n; i++) {
        cin >> x;
        curr->next = new Node(x);
        curr = curr->next;
    }

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