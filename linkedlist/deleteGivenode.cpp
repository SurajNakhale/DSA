#include <bits/stdc++.h>
using namespace std;

// Definition of a singly-linked list node
struct Node {
    int val;              
    Node* next;       
    Node(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(Node* node){
        Node* nextnode = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete nextnode;
    }
};
  // Driver code
int main() {
  // Create a linked list: 4 -> 5 -> 1 -> 9
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);

    // Suppose we want to delete node with value 5
    Solution sol;
    sol.deleteNode(head->next->next);  

    // Print updated list: expected output is 4 -> 1 -> 9
    Node* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}