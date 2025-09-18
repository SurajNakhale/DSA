/*Problem Statement:

There’s an array ‘A’ of size ‘N’ with an equal number 
of positive and negative elements. Without altering the 
relative order of positive and negative elements, you must 
return an array of alternately positive and negative values.

Note: Start the array with positive elements.

Examples:
Input:
arr[] = {1,2,-4,-5}, N = 4
Output:
1 -4 2 -5

Explanation: 

Positive elements = 1,2
Negative elements = -4,-5
To maintain relative ordering, 1 must occur before 2, 
and -4 must occur before -5.
*/
#include<bits/stdc++.h>
using namespace std;

// vector<int> rearrangearray(vector<int> a, int n){
//     vector<int> ans(n, 0);
//     int posindex = 0;
//     int negindex = 1;

//     for(int i=0; i<n; i++){
//         if(a[i] < 0){
//             ans[negindex] = a[i];
//             negindex += 2;
//         }else{
//             ans[posindex] = a[i];
//             posindex += 2;
//         }
//     }
//     return ans;
// }

/*Problem Statement:
There’s an array ‘A’ of size ‘N’ with positive
and negative elements (not necessarily equal). 
Without altering the relative order of positive 
and negative elements, you must return an array 
of alternately positive and negative values. The 
leftover elements should be placed at the very end 
in the same order as in array A.
Note: Start the array with positive elements.

Example 1:

Input:
arr[] = {1,2,-4,-5,3,4}, N = 6
Output:
1 -4 2 -5 3 4*/






vector<int> rearrangearray(vector<int> a, int n){
    vector<int> pos;
    vector<int> neg;
    
    for(int i=0; i<n ; i++){
        if(a[i] < 0){
            neg.push_back(a[i]);
        }else{
            pos.push_back(a[i]);
        }

        if(neg.size() < pos.size()){
            for(int i=0; i<neg.size(); i++){
                a[i*2] = pos[i];
                a[i*2+1] = neg[i];
            }
            int index = neg.size() * 2;
            for(int i=neg.size(); i<pos.size(); i++){
                a[index] = pos[i];
                index++;
            }
            
        }else{
            for(int i=0; i<pos.size(); i++){
                a[i*2] = pos[i];
                a[i*2+1] = neg[i];
            }
            int index = pos.size() * 2;
            for(int i = pos.size(); i<neg.size(); i++){
                a[index] = neg[i];
                index++;
            }
        }
    }
    return a;
}




int main(){
    vector<int> a = {1,2,-4,-5,4,-5,5,4,4,4,-3};
    int n = a.size();
    vector<int> result = rearrangearray(a, n);
    for(int i=0; i<n; i++){
        cout << result[i] << " ";  
    }

}