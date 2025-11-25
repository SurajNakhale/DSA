#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

void printLinkedList(Node* list1){
    Node* temp = list1;
    while(temp){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

Node* sortTwoLinkedLists(Node* list1, Node* list2){
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    if(list1->data > list2->data){
        swap(list1, list2);
    }

    Node* res = list1;
    while(list1 != NULL && list2 != NULL){
        Node* temp = NULL;
        while(list1 != NULL && list1->data <= list2->data){
            temp = list1;
            list1 = list1->next;
        }
        temp->next = list2;

        swap(list1, list2);
    }
    return res;
}

int main() {
    // Example Linked Lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLinkedList(list1);

    cout << "Second sorted linked list: ";
    printLinkedList(list2);

    Node* mergedList = sortTwoLinkedLists(list1, list2);
    cout<<"\n";
    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}