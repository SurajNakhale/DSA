// Remove duplicates from sorted array

// Given an integer array nums sorted in non-decreasing order,
// remove all duplicates in-place so that each unique element appears\
// only once. Return the number of unique elements in the array.
// If the number of unique elements be k, then,

// Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.
// The remaining elements, as well as the size of the array does not matter in terms of correctness.

// An array sorted in non-decreasing order is an array where every element to the right of an element is either equal to or greater in value than that element.

// Examples:
// Input: nums = [0, 0, 3, 3, 5, 6]
// Output: 4
// Explanation: Resulting array = [0, 3, 5, 6, _, _]

// Input: nums = [-2, 2, 4, 4, 4, 4, 5, 5]
// Output: 4
// Explanation: Resulting array = [-2, 2, 4, 5, _, _, _, _]

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j<nums.size(); j++){
            if(nums[j] != nums[i-1]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};