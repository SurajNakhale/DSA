
#include<bits/stdc++.h>
using namespace std;

struct Node
{   
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* convertarrtoll(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* removeNthfromEnd(Node* head, int n){
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* fast = dummy;
    Node* slow = dummy;

    for(int i = 1; i<=n; i++){
        fast = fast->next;
    }

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }

    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return dummy->next;
}




int main(){

    vector<int> arr = {2, 5, 6, 3, 4};
    Node* head = convertarrtoll(arr);
    int n = 4;
    head = removeNthfromEnd(head, n);
    Node* temp = head;
    while(temp ){
        cout<< temp->data << " ";
        temp = temp->next;
    }

}