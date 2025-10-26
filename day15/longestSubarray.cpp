/*
Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

Examples

Example 1:
Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result: 5
Explanation: The following subarrays sum to zero:
{-3, 3} , {-1, 6, -5}, {-3, 3, -1, 6, -5}
Since we require the length of the longest subarray, our answer is 5!
*/
//brute force approach

#include<bits/stdc++.h>
using namespace std;

int bruteSol(vector<int> nums, int target){
    int n = nums.size();
    int maxlen = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += nums[k];
            }
            if(sum == target) maxlen = max(maxlen, j-i+1);
        }
    }
    return maxlen;
}
int bruteSol2 (vector<int> nums, int target){
    int n = nums.size();
    int maxlen = 0;

    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += nums[j];
            if(sum == target) maxlen = max(maxlen, j-i+1);
        }
    }
    return maxlen;
}
// optimal solution for the arrays with positive negative and zeros in it
int better (vector<int> nums, int target){
    map<long long, int> preSum;
    int maxlen = 0;
    int n = nums.size();
    int sum = 0;
    for(int i=0; i<n; i++){
         sum += nums[i];
         if(sum == target){
            maxlen = max(maxlen, i+1);
         }

         int rem = sum - target;
         if(preSum.find(rem) != preSum.end()){
            int len = i - preSum[rem];
            maxlen = max(maxlen, len);

         }
         if(preSum.find(sum) == preSum.end()){
            preSum[sum] = i;
         }
    }
    return maxlen;
}

int optimal (vector<int> nums, int target){
    int n = nums.size();
    int left = 0; 
    int right = 0;
    int maxlen = 0;
    int sum = 0;

    while(right < n){
        sum += nums[right];
        
        //shrink the window if the sum exceeds
        while(sum > target && left <= right){
            sum -= nums[left];
            left++;
        }

        //for valid sub array
        if(sum == target){
            maxlen = max(maxlen, right-left+1);
        } 
        
        right++;
    }
    return maxlen;

}
int main(){

    vector<int> nums = {4, 2, 2, 6, 4};
    int target = 6;
    // cout<< "Longest subarray with sum k: "<< bruteSol2(nums, target);
    // cout<< "Longest subarray with sum k: "<< better(nums, target);
    cout<< "Longest subarray with sum k: "<< optimal(nums, target);
    
    return 0;
}