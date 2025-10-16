/*
Majority Elements(&gt;N/3 times) | Find the elements that appears more than N/3 times in the array

Problem Statement: Given an array of N integers. Find the elements 
that appear more than N/3 times in the array. If no such element exists, return an empty vector.

Pre-requisite: Majority Element(>N/2 times)

Examples

Example 1:
Input Format: N = 5, array[] = {1,2,2,3,2}
Result: 2
Explanation: Here we can see that the Count(1) = 1, 
Count(2) = 3 and Count(3) = 1.Therefore,
 the count of 2 is greater than N/3 times. Hence, 2 is the answer.

Example 2:
Input Format:  N = 6, array[] = {11,33,33,11,33,11}
Result: 11 33
Explanation: Here we can see that the Count(11) = 3 and 
Count(33) = 3. 
Therefore, the count of both 11 and 33 is greater than N/3 times. Hence, 11 and 33 is the answer.

*/
#include<bits/stdc++.h>
using namespace std;
//  vector<int> majorityElement(vector<int> arr){
//     int n = arr.size();
//     vector<int> ls;
//         for(int i=0; i<n; i++){
//             bool alreadyexist = false;
//             for(int x : ls){
//                 if(x == arr[i]){
//                     alreadyexist = true;
//                     break;
//                 }
//             }
//             if(alreadyexist){
//                 continue;
//             }
//                 int cnt = 0;
//                 for(int j=0; j<n; j++){
//                     if(arr[i] == arr[j]){
//                         cnt++;
//                     }
//                 }
//                 if(cnt > n/3){
//                     ls.push_back(arr[i]);
//                 }
//             }    
//     if(ls.size() == 0) cout<<"no majority element found!";
//     return ls;
// }



//better solution using hashing element,count
// vector<int> majorityElement(vector<int> arr){
//     int n = arr.size();
//     vector<int> ls;
//     map<int, int> map;
//     int mini = n/3 + 1;
//     for(int i=0; i<n; i++){
//         map[arr[i]]++;
//         if(map[arr[i]] == mini || map[arr[i]] > mini){
//             ls.push_back(arr[i]);
//         }
//     }
//     if(ls.size() == 0) cout<<"no majority element";
//     return ls;
// }


//optimal solution
vector<int>majorityElement(vector<int> arr){
    int cnt1=0;
    int cnt2=0;

    int ele1= INT_MIN;
    int ele2= INT_MIN;

    for(int i=0; i<arr.size(); i++){
        if(cnt1 == 0 && ele2 != arr[i]){
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && ele1 != arr[i]){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ls;
    cnt1=0, cnt2=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == ele1) cnt1++;
        if(arr[i] == ele2) cnt2++;
    }

    int mini = int(arr.size()/3) +1;
    if(cnt1 >= mini) ls.push_back(ele1);
    if(cnt2 >= mini) ls.push_back(ele2);

    return ls;
}

int main(){ 
    vector<int> arr = {11,11,11,13,13,13};
    vector<int> ans = majorityElement(arr);
    for(auto it : ans){
        cout<< " ";
        cout<< it;
    }

    return 0;

}