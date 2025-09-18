//maximum sum subarray
/*
count n0. of element in array:
Array: int arr[5] = {10, 20, 30, 40, 50};
sizeof(arr): In this case, an int typically takes 4 bytes, so the array of 5 integers occupies 5 * 4 = 20 bytes.
sizeof(arr[0]): The size of the first element (int arr[0]) is 4 bytes.
Result: 20 bytes / 4 bytes = 5 elements.*/

#include<bits/stdc++.h>
using namespace std;

//brute force approach
// int maxiSum (vector<int> a, int n){
//     int maxi = INT_MIN;
//     for(int i = 0; i<n; i++){
//         for(int j = i; j<n; j++){
//             int sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum += a[k];
//             }
//             maxi = max(maxi, sum);
//         }
//     }


//     return maxi;
// }



//better approach
// int maxiSum (vector<int> a, int n){
//     int maxi = INT_MIN;
//     for(int i = 0; i<n; i++){
//         int sum = 0;
//         for(int j = i; j<n; j++){
//             sum += a[j];
//             maxi = max(maxi, sum);
//         }
//     }


//     return maxi;
// }









//optimal approach kadane algorithm
// int maxiSum(vector<int> a, int n){
//     int maxi = INT_MIN;
//     int sum = 0;

//     for(int i = 0; i<n; i++){
//             sum += a[i];
//             if(sum > maxi){
//                 maxi = sum;
//             }

//             if(sum < 0) sum = 0;

//         }

//     return maxi;
// }

//follow up question [print the max sum subarray]

int maxiSum(vector<int> a, int n){
    int maxi = INT_MIN;
    int sum = 0;
    int start = 0;
    int ans_start = -1;
    int ans_end = -1;

    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum == 0) start = i;

        if(sum > maxi){
            maxi = sum;
            ans_start = start;
            ans_end = i;
        }

        if(sum < 0){
            sum = 0;
        }


    }
    cout << "elements of subarray are: ";
    for(int i=ans_start; i<ans_end; i++  ){
        cout<<a[i]<<" ";
    }
    cout << "\n";

    return maxi;
}



int main(){
    vector<int> a = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = a.size();
    int ans  = maxiSum(a, n);

    cout<<"maximum sum of subarray is: "<<ans;
}

