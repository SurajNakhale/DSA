#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public:
    int data;
    Node* next;
    Node* back;

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
        back = nullptr;
    }


};

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

void print(Node* head){
    Node* temp = head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* deletehead(Node* head){
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL) return NULL;
    
    Node* tail = head;
    Node* prev = NULL;

    while (tail != NULL)
    {
        if(tail->next == nullptr){
            prev = tail->back;
            prev->next = nullptr;
            tail->back = nullptr;
            delete tail;
            break;
        }
        tail = tail->next;
    }
    return head ;
}

Node* deletekthELe(Node* head, int k){
    if(head == NULL) return NULL;

    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        delete temp;
        return NULL;
    }
    else if(prev == NULL){
        deletehead(temp);
    }
    else if(front == NULL){
        deleteTail(temp);
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    return head;
}
Node* deleteValue(Node* head, int val){
    if(head == NULL) return NULL;

    Node* temp = head;
    while(temp != NULL){
        if(temp->data == val) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* front = temp->next;

    if(prev == NULL && front == NULL){
        delete temp;
        return NULL;
    }
    else if(prev == NULL){
        deletehead(temp);
    }
    else if(front == NULL){
        deleteTail(temp);
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    return head;
}

Node* insertfirst(Node* head, int ele){
    Node* newnode = new Node (ele, head, nullptr);
    head->back = newnode;
    head = newnode;
    return head;
}
Node* insertTail(Node* head, int ele){
    if(head == NULL) return new Node(ele);

    Node* tail = head;
    while(tail != NULL){
        if(tail->next == nullptr){
            Node* x = new Node(ele, nullptr, tail);
            tail->next = x;
            break;
        }
        tail = tail->next;
    }
    return head;
}

Node* insertKthele(Node* head, int ele, int k){
    if(head == NULL) return new Node(ele);

    if(k == 1){
        insertfirst(head, ele);
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* x = new Node(ele, temp, prev);
    temp->back = x;
    prev->next = x;

    return head;
}

void insertNode(Node* node, int ele){
    Node* prev = node->back;
    Node* x = new Node(ele, node, prev);
    prev->next = x;
    node->back = x;
}
int main(){
    vector<int> arr = {2, 4, 5, 6};
    Node* head = convertArrtoDLL(arr);
    insertNode(head->next->next->next, 100);
    print(head);
    
}