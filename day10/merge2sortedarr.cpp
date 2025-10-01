//MERGE TWO SORTED ARRAY WITHOUT EXTRA SPACE

/*Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m 
in non-decreasing- ASCENDING order. Merge them in sorted order. Modify arr1 so that it 
contains the first N elements and modify arr2 so that it contains the last M elements.

Example2:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]

Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]

Explanation:
After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9

*/

#include<bits/stdc++.h>
using namespace std;

// void merge(long long arr1[], long long arr2[], int n, int m){
//     long long arr3[n+m];
//     int left = 0;
//     int right = 0;
//     int index = 0;

//     while(left<n && right<m){
//         if(arr1[left] < arr2[right]){
//             arr3[index] = arr1[left];
//             index++;
//             left++;
//         }
//         else{
//             arr3[index] = arr2[right];
//             index++;
//             right++;
//         }
//     }

//     while(left < n){
//         arr3[index] = arr1[left];
//         index++;
//         left++;
//     }
//     while(right<m){
//         arr3[index] = arr2[right];
//         index++;
//         right++;

//     }

//     for(int i=0; i<n+m; i++){
//         if(i<n) arr1[i] = arr3[i];
//         else arr2[i-n] = arr3[i]; 
//     }
// }
//optimal soultion


// void merge(long long arr1[], long long arr2[], int n, int m){
//     int left = n -1;
//     int right = 0;

//     while(left >= 0 && right < m){
//         if(arr1[left] > arr2[right]){
//             swap(arr1[left], arr2[right]);
//             left --;
//             right ++;

//         }
//         else{
//             break;
//         }

//     }
//     sort(arr1, arr1+n);
//     sort(arr2, arr2+m);

// }
 
// void swapifGreater(long long arr1[], long long arr2[], int index1, int index2){
//     if(arr1[index1] > arr2[index2]){
//         swap(arr1[index1], arr2[index2]);
//     }
// }
void merge(long long arr1[], long long arr2[], int n, int m){
    int len = n + m;
    int gap = (len / 2) + (len % 2);

    while(gap > 0){
        int left = 0;
        int right = left + gap;

        while(right < len){
            // Both pointers in arr1
            if(left < n && right < n){
                if(arr1[left] > arr1[right]){
                    swap(arr1[left], arr1[right]);
                }
            }
            // left in arr1, right in arr2
            else if(left < n && right >= n){
                if(arr1[left] > arr2[right - n]){
                    swap(arr1[left], arr2[right - n]);
                }
            }
            // Both pointers in arr2
            else{
                if(arr2[left - n] > arr2[right - n]){
                    swap(arr2[left - n], arr2[right - n]);
                }
            }
            left++;
            right++;
        }

        if(gap <= 1){
            break;
        } 
        gap = (gap / 2) + (gap % 2);
    }
}
int main(){
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4;
    int m = 3;
    cout<< "123";

    merge(arr1, arr2, n, m);
    cout << "arr1[] = ";
    for(int i =0; i<n ; i++){
        cout<< arr1[i] << " ";
    }
    cout<< "\narr2[] = ";
    for(int i=0; i<m; i++){
        cout<< arr2[i] << " ";
    }
    return 0;


}

/*class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;          // last index of valid elements in nums1
        int right = n - 1;         // last index in nums2
        int pos = m + n - 1;       // last position in nums1

        while (right >= 0) {
            if (left >= 0 && nums1[left] > nums2[right]) {
                nums1[pos--] = nums1[left--];
            } else {
                nums1[pos--] = nums2[right--];
            }
        }
    }
};

nums1 = [1,2,3,0,0,0], m = 3  
nums2 = [2,5,6],       n = 3
op:
nums1 = [1,2,2,3,5,6]*/