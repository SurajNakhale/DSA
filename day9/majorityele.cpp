/*Majority Elements(&gt;N/3 times) | Find the elements 
that appears more than N/3 times in the array

Example 1:
Input Format: N = 5, array[] = {1,2,2,3,2}
Result: 2
Explanation: Here we can see that the Count(1) = 1, Count(2) = 3 and Count(3) = 1.Therefore, 
the count of 2 is greater than N/3 times. Hence, 2 is the answer.*/
//brute force approach

#include<bits/stdc++.h>
using namespace std;
// vector<int> majorityEle(vector<int> arr){
//     int n = arr.size();

//     vector<int> ls;
//     for(int i=0; i<n; i++){
//         if(ls.size() == 0 || ls[0] != arr[i]){
//             int cnt = 0;
//             for(int j = 0; j<n; j++){
//                 if(arr[j] == arr[i]){
//                     cnt++;
//                 }
//             }
//             if(cnt > n/3){
//                 ls.push_back(arr[i]);
//             }

//             if(ls.size() == 2) break;
//         }

//     }
//     return ls;
    
// }
//better approach hash map using one loop
// vector<int> majorityEle(vector<int> arr){
//     int n = arr.size();
//     map<int, int> mpp;
//     vector<int> ls;
//     int mini = int(n/3) + 1;


//     for(int i=0; i<n; i++){
//         mpp[arr[i]]++;

//         if(mpp[arr[i]] == mini){
//             ls.push_back(arr[i]);
//         }
//         if(ls.size() == 2) break;
//     }
//     sort(ls.begin(), ls.end());

//     return ls;

// }


//optimal solution 
vector<int> majorityEle(vector<int> arr){
    int cnt1 = 0;
    int cnt2 = 0;
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    int n = arr.size();

    for(int i=0; i<n; i++){
        if(cnt1 == 0 && ele2 != arr[i]){
            ele1 = arr[i]; 
        }
        else if(cnt2 == 0 && ele1 != arr[i]){
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
    int c1=0, c2=0;
    for(int i=0; i<n; i++){
        if(arr[i] == ele1) c1++;
        if(arr[i] == ele2) c2++;
    }
    int mini = int(n/3) +1;
    if(c1 >= mini) ls.push_back(ele1);
    if(c2 >= mini) ls.push_back(ele2);

    return ls;
}

int main(){
    vector<int>arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityEle(arr);
    for(auto it : ans){
        cout<< it<< " ";
        cout<< "\n";
    }
    return 0;


}