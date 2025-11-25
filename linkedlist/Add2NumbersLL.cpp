
#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;


    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

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

Node* Add2NumbersLL(Node* l1, Node* l2){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry != 0){
        int sum = 0;
        if(l1 != NULL){
            sum += l1->data;
            l1 = l1->next;
        }

        if(l2 != NULL){
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum/10;
        Node* node = new Node(sum%10);
        temp->next = node;
        temp = node;
    }
    return dummy->next;
}


int main() {
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

    Node* mergedList = Add2NumbersLL(list1, list2);
    cout<<"\n";
    cout << "Merged sorted linked list: ";
    printLinkedList(mergedList);

    return 0;
}