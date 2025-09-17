/*The steps are as follows:
Brute force apporach
            First, we will run a loop(say i) that will select every possible starting
            index of the subarray. The possible starting 
            indices can vary from index 0 to index n-1(n = size of the array).
            Inside the loop, we will run another loop(say j) that will signify the
            ending index of the subarray. For every subarray 
            starting from the index i, the possible ending index can vary from index i
            to n-1(n = size of the array).
            After that for each subarray starting from index i and ending at index j
            (i.e. arr[i….j]), we will run another loop to
            calculate the sum of all the elements(of that particular subarray).
            If the sum is equal to k, we will consider its length i.e. (j-i+1). Among
            all such subarrays, we will consider the maximum 
            length by comparing all the lengths.
*/


#include<bits/stdc++.h>
using namespace std;

// int longestSubarray(vector<int> &a, long long k){
//     int n = a.size();
//     int len = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             long long sum = 0;
//             for(int k=i; k<=j; k++){
//                 sum += a[k];
            
//             }
//             if(sum == k){
//                 len = max(len, j - i + 1);
//             }
//         }
//     }
//     return len;

// }


// better solution


// int longestSubarray(vector<int> &a, long long k){
//     int n = a.size();
//     int len = 0;
    
//     for(int i=0; i<n; i++){//starting index
//         int sum = 0;
//         for(int j=i; j<n; j++){//ending index
//             // add the current element to
//             // the subarray a[i...j-1]:
//             if(i<j){
//                 sum += a[j];
//             }
//             if(sum == k) len = max(len, j-i+1);
//         }
//     }
//     return len;
// }




//better approach hashmaps

// int longestSubarray(vector<int> &a, long long k){
//     map<long long, int> premap; //store  sum and indices
//     int n = a.size();
//     long long sum = 0;
//     int maxLen = 0;

    
//     for(int i=0; i<n; i++){
//         sum += a[i];

//         if(sum == k){
//             maxLen = max(maxLen, i+1);
//         }

//         //calculating the sum of remaning part
//         long long rem = sum-k;
//         if(premap.find(rem) !=  premap.end()){
//            int len = i - premap[rem];
//            maxLen = max(maxLen, len);

//         }
//         //finally updating the map
//         if(premap.find(sum) == premap.end()){
//             premap[sum] = i;

//         }

//     }
//     return maxLen;
// }




//optimal soultion  - 2 pointer approach

int longestSubarray(vector<int> &a, long long k){
    int left = 0;
    int right = 0;
    int sum = a[0];
    int n = a.size();
    int maxLen = 0;

    while(right<n){
//sum > k reduce the sum array from left until the subarray becomes less than k 

        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }
//if sum equales to k then update maxlen i.e answer
        if(sum == k) maxLen = max(maxLen, right-left+1);

        right++;
        sum += a[right];

    }
    return maxLen;
}

int main(){
    vector<int> a = {2,3,5,1,9};
    long long k = 10;
    int len = longestSubarray(a, k);
    cout << len;
    return 0;

}