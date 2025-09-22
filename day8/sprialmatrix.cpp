/*Spiral Traversal of Matrix
Problem Statement: Given a Matrix, print the given matrix in spiral order.

Examples:

Example 1:
Input: Matrix[][] = { 
                    { 1, 2, 3, 4 },
		            { 5, 6, 7, 8 },
		            { 9, 10, 11, 12 },
	                { 13, 14, 15, 16 }
                }

Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
Explanation: The output of matrix in spiral form.

Example 2:
Input: Matrix[][] = { { 1, 2, 3 },
	              { 4, 5, 6 },
		      { 7, 8, 9 } }
			    
Output: 1, 2, 3, 6, 9, 8, 7, 4, 5.
Explanation: The output of matrix in spiral form.

appproach:

1st loop: This will print the elements from left to right.

2nd loop: This will print the elements from top to bottom.

3rd loop: This will print the elements from right to left.

4th loop: This will print the elements from bottom to top.

*/

#include<bits/stdc++.h>
using namespace std;
vector<int> printSpiral(vector<vector<int>> &matrix){
    vector<int> ans;
    int n = matrix.size();
    int m = matrix[0].size();
    int left = 0;
    int top = 0;
    int right = n-1;
    int bottom = m-1;


    while(top<=bottom && left<=right){
        for(int i=left; i<=right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;

        for(int i=top; i<=bottom; i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom; i>= top; i--){
                ans.push_back(matrix[i][left]);

            }
            left++;
            
        }
    }
    return ans;


}
int main() {
  //Matrix initialization.
  vector<vector<int>> matrix   {{1, 2, 3, 4},
                             {5, 6, 7, 8},
	                         {9, 10, 11, 12},
		                     {13, 14, 15, 16}};
		                     
  vector<int> ans = printSpiral(matrix);

  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  
  return 0;
}