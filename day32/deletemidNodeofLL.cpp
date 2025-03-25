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

// Function to delete the middle node of a linked list
Node* deleteMiddle(Node* head) {
    if (head == NULL || head->next == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;  // To track the node before the middle

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow is now pointing to the middle node
    prev->next = slow->next;  // Remove the middle node
    delete slow;  // Free memory
    return head;
}

// Function to create a linked list from a vector
Node* vectorToLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (size_t i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Function to print the linked list
void printLL(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};  // Example list
    Node* head = vectorToLL(arr);

    cout << "Original List: ";
    printLL(head);

    head = deleteMiddle(head);

    cout << "After Deleting Middle Node: ";
    printLL(head);

    return 0;
}
