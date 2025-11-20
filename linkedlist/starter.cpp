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

int lengthofLL(Node* head){
    int cnt = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}


Node* removehead(Node* head){
    Node* temp = head;
    temp = head->next;
    delete head;// in java it is handeled by garbage collector but in c++ we have manually remove the space
    return temp;
}


Node*  removeTail(Node* head ){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;

    while (temp->next->next != nullptr){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    
return head;
}

Node* deleteKelement(Node* head, int k ){
    if(head == NULL) return head;

    if(k == 1){
        Node* temp = head;
        temp = head->next;
        delete head;
        return temp;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;

    }
    return head;

}


Node* deleteByValue(Node* head, int val ){
    if(head == NULL) return head;

    if(head->data == val){
        Node* temp = head;
        temp = head->next;
        delete head;
        return temp;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == val){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;

    }
    return head;

}


int main(){

    vector<int> arr = {2, 5, 6, 3};
    Node* head = convertarrtoll(arr);
    


    
    // head = deleteByValue(head, 2);
    // Node* temp = head;
    // while(temp){
    //     cout<< temp->data << " ";
    //     temp = temp->next;
    // }
    

    // head = deleteKelement(head, 1);
    // Node* temp = head;
    // while(temp){
    //     cout<< temp->data << " ";
    //     temp = temp->next;
    // }
    
    //remove tail    
    // Node* temp = removeTail(head);

    // while(temp){
    //     cout<< temp->data << " ";
    //     temp = temp->next;
    // }


    //remove first element
    // head = removehead(head);
    // cout<< head->data;


    //print length of LL
    // cout<< lengthofLL(head)<< "\n";

    //travesrsal in LL
    // Node* temp = head;
    // while(temp){
    //     cout<< temp->data << " ";
    //     temp = temp->next;
    // }

    // cout<< "\n";

    //print data at head
    // cout<< head->data << " \n";
    // Node* y = new Node(arr[0]);
    // cout<< y->data;
}