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

// Function to find the tail of a doubly linked list
Node* findTail(Node* head) {
    Node* temp = head;
    while (temp && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

// Function to find pairs with sum k in a sorted doubly linked list
vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int, int>> ans;
    if (head == NULL) return ans;

    Node* left = head;
    Node* right = findTail(head);

    while (left != NULL && right != NULL && left != right && left->prev != right) {
        int sum = left->data + right->data;
        if (sum == k) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev; // Move both pointers
        } 
        else if (sum < k) {
            left = left->next;
        } 
        else {
            right = right->prev;
        }
    }
    return ans;
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

// Function to print the linked list
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
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 8);
    insert(head, 9);

    cout << "Doubly Linked List: ";
    printList(head);

    int k = 10;
    vector<pair<int, int>> pairs = findPairs(head, k);

    cout << "Pairs with sum " << k << ": ";
    for (auto &p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}
