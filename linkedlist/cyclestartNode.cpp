#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    // Function to detect the starting point of the loop using Floyd’s algorithm
    Node* detectCycle(Node* head) {
        if(head == NULL || head->next == NULL) return NULL;

        Node* slow = head;
        Node* fast = head;
        Node* temp = head;

        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                while(slow != temp){
                    slow = slow->next;
                    temp = temp->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};

// Driver code
int main() {
    // Create nodes
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);

    // Create a cycle: connect tail to index 1 node (value 2)
    head->next->next->next->next = head->next;

    Solution obj;
    Node* result = obj.detectCycle(head);

    if (result != NULL)
        cout << "Cycle starts at node with value: " << result->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}