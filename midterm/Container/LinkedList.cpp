#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void display(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, value;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> value;
        insert(head, value);
    }
    
    cout << "Linked List elements: ";
    display(head);
    
    return 0;
}