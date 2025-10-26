// Problem Statement: You are given an array of ‘N’ integers.
//  You need to find the length of the longest sequence which contains the consecutive elements.

// Examples

// Example 1:

// Input: [100, 200, 1, 3, 2, 4]

// Output: 4

// Explanation: The longest consecutive subsequence is 1, 2, 3, and 4.

// Input: [3, 8, 5, 7, 6]

// Output: 4

// Explanation: The longest consecutive subsequence is 5, 6, 7, and 8.


//brute force approach
#include<bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int> &nums, int target) {
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] == target) {
            return true;
        }
    }
    return false;  // Only after full loop
}

int bruteapp(vector<int> &nums){
    int n = nums.size();
    int longest = 1;

    for(int i=0; i<n; i++){
        int x = nums[i];
        int cnt = 1;
        while(linearSearch(nums, x+1) == true){
            x = x+1;
            cnt = cnt+1;
        }
        longest = max(longest, cnt);
    }

    return longest;

}

int betterapp(vector<int> &nums){
 int n = nums.size();
 sort(nums.begin(), nums.end());
 int lastSmaller = INT_MIN;
 int cnt = 0; 
 int longest = 1;
    
    for(int i=0; i<n; i++){
        if(nums[i] -1 == lastSmaller){
            cnt = cnt + 1;
            lastSmaller = nums[i];
        }
        else if(nums[i] != lastSmaller){
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(longest, cnt);
    }

    return longest;
}

int optimalapp(vector<int> &nums){
    int n = nums.size();
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(nums[i]);

    }

    for(auto it : st){
        if(st.find(it -1) == st.end()){
            int x = it;
            int cnt = 1;
            while(st.find(x+1) != st.end()){
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> nums = {100, 200, 1, 3, 2, 4};
    
    int result = bruteapp(nums);
    int result2 = betterapp(nums);
    int result3 = optimalapp(nums);

    cout << "result: "<< result<<"\n";
    cout << "result: "<< result2<< "\n";
    cout << "result: "<< result3;

    return 0;

}