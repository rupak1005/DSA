#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

Node* rotate(Node* head, int k) {
    if (head == NULL || k == 0) return head;

    // Find the length of the list and the tail node
    Node* tail = head;
    int length = 1;
    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Adjust k if it is greater than the length of the list
    k = k % length;
    if (k == 0) return head;

    // Find the new last node (length - k)
    Node* newLast = head;
    for (int i = 1; i < length - k; i++) {
        newLast = newLast->next;
    }

    // Perform the rotation
    Node* newHead = newLast->next;
    newLast->next = NULL;
    tail->next = head;

    return newHead;
}

// Helper function to convert vector to linked list
Node* vector2LL(vector<int>& arr) {
    if (arr.empty()) return NULL;
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (size_t i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Print linked list
void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* head = vector2LL(arr);

    cout << "Original List: ";
    printLL(head);

    int k = 3;
    head = rotate(head, k);

    cout << "Rotated List by " << k << ": ";
    printLL(head);

    return 0;
}
