#include<bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    // public:
    // int data;
    // Node* next;
    
    public:
    int data;
    Node* next;
    Node* back;
    

    // public:
    // Node(int data1, Node* next1){
    //     data = data1;
    //     next = next1;
    // }

    // public: 
    // Node(int data1){
    //     data = data1;
    //     next = nullptr;
    // }

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public: 
    Node(int data1){
        data = data1;
        next = nullptr;
        back =nullptr;
    }
};

Node* convertArrtoLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1; i<arr.size(); i++){
        Node* x = new Node(arr[i]);
        temp->next = x;
        temp = x;
    }
    return head;
}
Node* convertArrtoDLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++ ){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* reverseDLL(Node* head){
    Node* last = NULL;
    Node* current = head;
    while(current != NULL){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    
    return last->back;

}

Node* reverseLL(Node* head){
    Node* current = head;
    Node* prev = nullptr;
    while(current != nullptr){
        Node* temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev;
}

int main(){
    vector<int> arr = {2, 5, 6, 3};
    Node* head = convertArrtoDLL(arr);
    head = reverseDLL(head);
    Node* temp = head;
    while(temp ){
        cout<< temp->data << " ";
        temp = temp->next;
    }

}