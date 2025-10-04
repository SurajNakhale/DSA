/*Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' 
where 'N' and 'M' denote the number of rows and columns, respectively. The
elements of each row are sorted in non-decreasing order. Moreover, the first
element of a row is greater than the last element of the previous row 
(if it exists). You are given an integer ‘target’, and your task is to
find if it exists in the given 'mat' or not.


Examples
Example 1:
Input Format: N = 3, M = 4, target = 8,
mat[] = 
1 2 3 4
5 6 7 8 
9 10 11 12
Result: true
Explanation: The ‘target’  = 8 exists in the 'mat' at index (1, 3).*/
#include<bits/stdc++.h>
using namespace std;

//brute force
bool searchmatrix(vector<vector<int>> &matrix, int target ){
    int n = matrix.size();
    int m = matrix[0].size();
// traverse throug entire matrix
    for(int i=0; i<n; i++){
        for(int j=0; i<m; j++){
            if(matrix[i][j] == target) return true;
        }
    }
    return false;
}

//better approach
bool binarysearch(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0; 
    int high = n-1;

    while(low<=high){
        int mid = low+high/2;
        if(nums[mid] == target) return true;
        else if(nums[mid] < target) low = mid+1;
        else high = mid + 1;
    }
    return false;
}
bool searchmatrixbetter(vector<vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i=0 ;i<n; i++){
        if(matrix[i][0] < target && target <= matrix[i][m - 1]){
            return binarysearch(matrix[i], target);
        }
    }
    return false;

}


//optimal solution:
bool searchmatrixopt(vector<vector<int>> &matrix, int target){
 int n = matrix.size();
 int m = matrix[0].size();
 int low = 0;
 int high = m*n -1;

 while(low <= high){
    int mid = low + (high - low) / 2;  
    int row = mid/m;
    int col = mid%m;

    if(matrix[row][col] == target) return true;
    else if(matrix[row][col] < target) low = mid+1;
    else high = mid-1;

 }
 return false;
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchmatrix(matrix, 8) == true ? cout<< "true\n" : cout<<"false\n";
    searchmatrixbetter(matrix, 8) == true ? cout<< "true\n" : cout<<"false\n";
    searchmatrixopt(matrix, 8) == true ? cout<< "true\n" : cout<<"false\n";
}