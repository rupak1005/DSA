#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    Node(int data1) {
        data = data1;
        next = nullptr;
        child = nullptr;
    }
};

Node* vector2LL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void printFlattenedLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        if (temp->child) {
            cout << " (child: " << temp->child->data << ") ";
        }
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* flattenLL(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->child) {
            Node* nextnode = temp->next;
            Node* child = temp->child;
            temp->next = child;
            child->next = nextnode;
            temp->child = NULL;
        }
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = vector2LL(arr);
    head->child = new Node(7);
    head->child->next = new Node(8);
    head->child->next->child = new Node(9);
    head->child->next->child->next = new Node(10);
    head->child->next->child->next->next = new Node(11);

    cout << "Original List: ";
    printFlattenedLL(head);

    head = flattenLL(head);

    cout << "Flattened List: ";
    printLL(head);

    return 0;
}