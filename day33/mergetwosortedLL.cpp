#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) {
        data = val;
        next = nullptr;
    }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    Node<int>* dummynode = new Node<int>(-1);
    Node<int>* temp = dummynode;

    while (first != NULL && second != NULL) {
        if (first->data < second->data) {
            temp->next = first;
            first = first->next;
        } else {
            temp->next = second;
            second = second->next;
        }
        temp = temp->next;
    }

    // Append the remaining nodes of the non-empty list
    if (first != NULL) {
        temp->next = first;
    } else {
        temp->next = second;
    }

    return dummynode->next; // Returning the merged sorted list
}

// Helper function to create linked list from a vector
Node<int>* vector2LL(std::vector<int> arr) {
    if (arr.empty()) return nullptr;
    Node<int>* head = new Node<int>(arr[0]);
    Node<int>* prev = head;
    for (size_t i = 1; i < arr.size(); i++) {
        Node<int>* temp = new Node<int>(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// Helper function to print linked list
void printLL(Node<int>* head) {
    while (head != nullptr) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    std::vector<int> list1 = {1, 3, 5, 7};
    std::vector<int> list2 = {2, 4, 6, 8};

    Node<int>* first = vector2LL(list1);
    Node<int>* second = vector2LL(list2);

    std::cout << "List 1: ";
    printLL(first);
    std::cout << "List 2: ";
    printLL(second);

    Node<int>* merged = sortTwoLists(first, second);

    std::cout << "Merged List: ";
    printLL(merged);

    return 0;
}
