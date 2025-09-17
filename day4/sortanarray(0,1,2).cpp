/*Sort an array of 0's 1's and 2's
Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.
The sorting must be done in-place, without making a copy of the original array.
Examples:
Input: nums = [1, 0, 2, 1, 0]

Output: [0, 0, 1, 1, 2]
Explanation:
The nums array in sorted order has 2 zeroes, 2 ones and 1 two*/


#include <bits/stdc++.h>
using namespace std;

// void sortArray(vector<int> &a, int n){
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0;

//        for(int i=0; i<n; i++){
//         if(a[i]==0) cnt0++;
//         else if(a[i]==1) cnt1++;
//         else cnt2++;
//        }

//        for(int i=0; i<cnt0; i++) a[i] = 0;
//        for(int i=cnt0; i< cnt0 + cnt1; i++) a[i] = 1;
//        for(int i=cnt1+cnt0; i< a.size(); i++) a[i] = 2;


//     }




/*This problem is a variation of the popular Dutch National flag algorithm. 

This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.
  The rules are the following:

arr[0….low-1] contains 0. [Extreme left part]
arr[low….mid-1] contains 1.
arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array

The middle part i.e. arr[mid….high] is the unsorted segment. 
So, hypothetically the array with different markers will look like the following:
In our case, we can assume that the entire given array is
 unsorted and so we will place the pointers accordingly. For example, if the given array is: [2,0,2,1,1,0], the array with the 3 pointers will look like the following:
Here, as the entire array is unsorted, we have placed the 
mid pointer in the first index and the high pointer in the last index. The low is also pointing to the first index as we have no other index before 0. Here, we are mostly interested in placing the ‘mid’ pointer and the ‘high’ pointer as they represent the unsorted part in the hypothetical array.
Now, let’s understand how the pointers will work to make 
the array sorted.*/

void sortArray(vector<int> &a, int n){
    int low=0, mid=0, high = n-1;
    
    while(mid <= high){
        if(a[mid] == 0){
            swap(a[mid], a[low]);
            mid++;
            low++;
        }
        else if(a[mid] == 1){
            mid++;

        }else{
            swap(a[mid], a[high]);
            high--;

        }
    }
}
int main(){
    int n = 6;
    vector<int> a = { 0,1,2,1,2,2};
    sortArray(a, n);
    cout<<"sorted array:";
    for(int i=0; i<n; i++){
        cout<<a[i];
    }
    return 0;

}