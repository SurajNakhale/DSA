// Second Largest Element

// Given an array of integers nums, return the second-largest element
// in the array. If the second-largest element does not exist, return -1.

// Examples:
// Input: nums = [8, 8, 7, 6, 5]
// Output: 7


// Input: nums = [10, 10, 10, 10, 10]
// Output: -1
// Explanation: The only value in nums is 10, so there is no second largest value, thus -1 is returned


class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        //your code goes here
      int largest = nums[0];
      int slargest = INT_MIN;

      if(nums.size() < 2) return -1;

      for (int i=1; i<nums.size(); i++){
        if(nums[i]>largest){
            slargest = largest;
            largest = nums[i];
        }
        else if(nums[i] < largest && nums[i] > slargest){
            slargest = nums[i];
        }
      }
      return (slargest == INT_MIN) ? -1 : slargest;
    }
};