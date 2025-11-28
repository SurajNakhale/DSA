#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
    }

    public:
    Node(){
        data = 0;
        next = nullptr;
    }
};

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}
Node* reverseLL(Node* node){
    Node* prev = NULL;
    Node* nex = NULL;

    while(node != NULL){
        nex = node->next;
        node->next = prev;
        prev = node;
        node = nex;
    }
    return prev;
}

bool isPalindrome(Node* head){
    if(head == NULL || head->next == NULL) return false;
    Node* dummy = head;
    Node* slow = dummy;
    Node* fast = dummy;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseLL(slow->next);

    slow = slow->next;

    while(slow != NULL){
        if(dummy->data != slow->data) return false;
        dummy = dummy->next;
        slow = slow->next;
    }
    return true;
}


int main() {
    // Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}