/*Problem Statement: Given an array of N + 1 size, 
where each element is between 1 and N. Assuming there 
is only one duplicate number, your task is to find the duplicate number.

Examples:

Example 1: 

Input: arr=[1,3,4,2,2]

Output: 2

Explanation: Since 2 is the duplicate number the answer will be 2.
*/

//brute force 

#include<bits/stdc++.h>
using namespace std;

// int duplicatenum(vector<int> &arr){
//     int n = arr.size();
//     vector<int> freq(n+1, 0);
    
//     for(int i=0; i<n; i++){
//         if(freq[arr[i]] == 0){
//             freq[arr[i]] += 1;
//         }
//         else{
//             return arr[i];
//         }
//     }
//     return -1;
// }//tc => n sc=> n

//optimal soltion
// consider a slow pointer moves by 1 fast pointer by 2 they are bound to
// meet at same position after this move the fast pointer to index 0 and let 
//slow pointer as it is 
//agin move the slow and fast pointer nd then they had to meet at some of position 
//that meeting index is our answer
// vector<int> nums = {1, 3, 4, 2, 2};
// Here's how the array can be interpreted:

// Index 0 → value 1

// Index 1 → value 3

// Index 3 → value 2

// fast = nums[nums[0]];

// // Step-by-step:
// nums[0] = 1
// nums[nums[0]] = nums[1] = 3

// => fast = 3
// 🧠 What’s the Idea?
// You're treating each element of the array as a "pointer" to the next index.
// This turns the array into a linked list structure where:
// i → nums[i] → nums[nums[i]] and so on.
// Because there is a duplicate number, there will be a cycle in this structure.
// fast = nums[nums[0]] moves the pointer 2 steps forward.
int duplicatenum(vector<int> &arr){
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];

    }while(slow != fast);

    fast = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return fast;
}

//brute
int duplicatenumBrute(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i=0; i<n; i++){
        if(arr[i] == arr[i+1]){
            return arr[i];
        }
    }
    return -1;

}
int main(){
    vector<int> arr = {1,3,4,2,2};
    cout<< "duplicate number:";
    cout<< duplicatenum(arr);
    cout<<"\nbrute force approach:"<< duplicatenumBrute(arr);
    return 0;

}