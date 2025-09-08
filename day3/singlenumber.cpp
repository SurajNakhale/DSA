// Single Number - I
// Given an array of nums of n integers. Every integer in the array appears 
//twice except one integer. Find the number that appeared once in the array.


// Examples:
// Input : nums = [1, 2, 2, 4, 3, 1, 4]

// Output : 3

// Explanation : The integer 3 has appeared only once.

// Input : nums = [5]

// Output : 5

// Explanation : The integer 5 has appeared only once.

class Solution{    
public:    
    int singleNumber(vector<int>& nums){
        //your code goes here
        int xor1 = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            xor1 = xor1^nums[i];

        }
        return xor1;
    }
};