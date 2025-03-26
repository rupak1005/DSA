#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to delete all occurrences of 'k' from a doubly linked list
Node* deleteAllOccurrences(Node* head, int k) {
    Node* temp = head;

    while (temp) {
        if (temp->data == k) {
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            // If the node to delete is the head
            if (temp == head) {
                head = nextNode;
            }

            // Adjust pointers to remove temp from the list
            if (prevNode) prevNode->next = nextNode;
            if (nextNode) nextNode->prev = prevNode;

            delete temp; // Free memory
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

// Function to insert a node at the end of a doubly linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to print the doubly linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 4);
    insert(head, 2);
    insert(head, 5);

    cout << "Original List: ";
    printList(head);

    int k = 2;
    head = deleteAllOccurrences(head, k);

    cout << "List after deleting " << k << ": ";
    printList(head);

    return 0;
}
