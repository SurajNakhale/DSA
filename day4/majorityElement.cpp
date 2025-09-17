// Majority Element (>n/2 times)

// Problem Statement: Given an array of N integers, 
// write a program to return an element that occurs 
// more than N/2 times in the given array. You may 
// consider that such an element always exists in the array.

//
/*
brute force approach
We will run a loop that will select the elements of the array one by one.
Now, for each element, we will run another loop and count its occurrence in the given array.
If any element occurs more than the floor of (N/2), we will simply return it.*/

#include<bits/stdc++.h>
using namespace std;



// int majorityElement(vector<int> a){
//     int n  = a.size();
//     for(int i=0; i<n; i++){
//         int cnt = 0;
//         for(int j=0; j<n; j++){
//             if(a[j] == a[i]){
//                 cnt++;
//             }
//         }
//         if(cnt > n/2){
//             return a[i];
//         }
//     }
//     return -1;
// }



/*using hashmap frequency array key-element value-occurance*/

// pair<int,int> majorityElement(vector<int> &a){
//     int n = a.size();
//     map<int, int> mpp;
//     for(int i=0; i<n; i++){
//         mpp[a[i]]++;
//     }
//     for(auto it : mpp){
//         if(it.second > n/2){
//             return {it.second, it.first};
//         }
//     }
//     return {-1,-1};
// }







/*using moves voting algorithm 
then verify the element 
return el*/



int majorityElement(vector<int> a){
    int cnt = 0;
    int el;
    int n = a.size();

    for(int i=0; i<n; i++){
        if(cnt == 0){
            el = a[i];
            cnt++;
        }
        else if(el == a[i]){
            cnt++;
        }
         else{
            cnt--;
        }
    }
    int count = 0;
    for(int i = 0; i<n ; i++){
        if(el == a[i]) count++;
    }

    if(count>n/2){
        return count;
    }
    return -1;

}



int main(){
 vector<int> a = {2, 2, 1, 1, 1, 2,2, 2, 2, 2};
 int ans = majorityElement(a);
 cout<<"the element:"<< ans<<"\n";
//  cout<<"the count of element:"<< ans.first<<"\n";
}