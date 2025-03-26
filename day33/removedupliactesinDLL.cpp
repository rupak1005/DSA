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

// Function to remove duplicates from a sorted doubly linked list
Node* removeDuplicates(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        Node* nextnode = temp->next;
        while (nextnode != NULL && nextnode->data == temp->data) {
            Node* duplicate = nextnode;
            nextnode = nextnode->next;
            delete duplicate;  // Correct memory deallocation
        }
        temp->next = nextnode;  // Update next pointer

        if (nextnode) nextnode->prev = temp;  // Update prev pointer
        temp = temp->next;  // Move temp forward
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
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 3);
    insert(head, 4);
    insert(head, 4);
    insert(head, 5);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
