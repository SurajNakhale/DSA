/*
Problem Statement: You are given an array of ‘N’ integers. 
You need to find the length of the longest sequence which 
contains the consecutive elements.

Examples
Input: [100, 200, 1, 3, 2, 4]
Output: 4
Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

Input: [3, 8, 5, 7, 6]
Output: 4
Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.
*/

// BruteForce
#include<bits/stdc++.h>
using namespace std;
// bool linearSearch(vector<int> &a, int nums){
//     int n = a.size();
//     for(int i = 0; i<n; i++){
//         if(a[i] == nums){
//             return true;
//         }
//     }
//     return false;
// }

// int longestSeq(vector<int> &a){
//     int n = a.size();
//     int longest = 1;

//     for(int i=0; i<n; i++){
//         int x = a[i];
//         int cnt = 1;
    
//         while(linearSearch(a, x+1) == true){
//             x += 1;
//             cnt += 1;
//         }
//          longest = max(longest, cnt);
//     }
//     return longest;

// }

//better solution
// int longestSeq(vector<int> &a){
//     int n = a.size();
//     int cnt = 0;
//     int longest = 1;
//     int last_smaller = INT_MIN;

//     sort(a.begin(), a.end());
//     for(int i=0; i<n; i++){
//         if(a[i] -1 == last_smaller){
//             cnt += 1;
//             last_smaller = a[i];
//         }
//         else if(a[i] != last_smaller){
//             cnt = 1;
//             last_smaller = a[i];
//         }

//         longest = max(longest, cnt);
//     }
//     return longest;
    
// }


//optimal solution using set data structure

int longestSeq(vector<int> &a){
   int n = a.size();
   unordered_set<int> st;
   if(n == 0) return 0;
    int longest = 1;
   for(int i=0; i<n; i++){
    st.insert(a[i]);
   }

   for(auto it : st){
    if(st.find(it - 1) == st.end()){
        int cnt = 1;
        int x = it;

        while(st.find(x+1) != st.end()){//true x+1 is present
            cnt += 1;
            x += 1;
        }
        longest = max(longest, cnt);
    }
   }
   return longest;
}


int main(){
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSeq(a);
    cout<<ans;
    return 0;
}