#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Recursive function to reverse a linked list
Node* reverserecur(Node* head) {
    if (head == NULL || head->next == NULL) return head;
    
    Node* newhead = reverserecur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

// Function to find the Kth node from the current position
Node* findkthnode(Node* temp, int k) {
    k -= 1;
    while (temp && k > 0) {  // FIXED: Should be `k > 0`
        k--;
        temp = temp->next;
    }
    return temp;
}

// Function to reverse linked list in groups of k
Node* kReverse(Node* head, int k) {
    if (!head || k == 1) return head; // No need to reverse if k = 1

    Node* temp = head;
    Node* prevLast = NULL;
    Node* newHead = NULL;

    while (temp != NULL) {
        Node* kthnode = findkthnode(temp, k);
        if (kthnode == NULL) {
            if (prevLast) prevLast->next = temp;
            break;
        }
        Node* nextnode = kthnode->next;
        kthnode->next = NULL;

        // Reverse the k-sized segment
        Node* reversedHead = reverserecur(temp);

        // Set the new head (for the first k group)
        if (newHead == NULL) {
            newHead = reversedHead;
        }

        // Connect the previous part to the new reversed segment
        if (prevLast) {
            prevLast->next = reversedHead;
        }

        prevLast = temp;
        temp = nextnode;
    }
    return newHead;
}

// Function to insert nodes into the linked list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);

    cout << "Original List: ";
    printList(head);

    int k = 3;
    head = kReverse(head, k);

    cout << "List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}
