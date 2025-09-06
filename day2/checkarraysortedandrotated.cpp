/*1752. Check if Array Is Sorted and Rotated

Given an array nums, return true if the array was 
originally sorted in non-decreasing order, then rotated 
some number of positions (including zero). Otherwise, return 
false.
There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array 
B of the same length such that B[i] == A[(i+x) % A.length] for 
every valid index i.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 2 positions to begin on 
the element of value 3: [3,4,5,1,2].*/

/*Example 1:
nums = [3, 4, 5, 1, 2]
Comparisons:

3 < 4 ✅

4 < 5 ✅

5 > 1 ❌ (drop)

1 < 2 ✅

2 < 3 ✅

Only 1 drop, so result = true

Example 2:
nums = [2, 1, 3, 4, 5]
Comparisons:

2 > 1 ❌ (drop)

1 < 3 ✅

3 < 4 ✅

4 < 5 ✅

5 > 2 ❌ (another drop)

2 drops, so result = false*/


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            int j = (i + 1) % n;  // wrap around to beginning
            if(nums[i] > nums[j]) {
                count++;  // count number of "drops"
            }
        }

        return count <= 1;  // only one drop allowed
    }
};
