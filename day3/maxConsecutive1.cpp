/*Given a binary array nums, return the maximum number of consecutive 1s in the array.
A binary array is an array that contains only 0s and 1s.
Examples:
Input: nums = [1, 1, 0, 0, 1, 1, 1, 0]

Output: 3

Explanation:

The maximum consecutive 1s are present from index 4 to index 6, amounting to 3 1s

Input: nums = [0, 0, 0, 0, 0, 0, 0, 0]

Output: 0

Explanation:

No 1s are present in nums, thus we return 0*/





int result(vector<int> &nums){
    int n = nums.size();
    int count = 0;
    int maxi = 0;

    for(int i=o; i<n; i++){
        if(nums[i]==1){
            count++;
            maxi = max(count,maxi);
        }
        else{
            count = 0;

        }
    }
    return maxi;
    
}