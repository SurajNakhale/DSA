// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

/*Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]

Output: [[7,4,1],[8,5,2],[9,6,3]]

Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.*/

// brute force

#include<bits/stdc++.h>
using namespace std;


// vector<vector<int>> rotate(vector<vector<int>> & matrix){
//     int n = matrix.size();

//     vector<vector<int>> ans(n, vector<int>(n,0));

//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             ans[j][n-1-i] = matrix[i][j];
//         }
//     }
//     return ans;

// }

//opitmal solution tc=0[n^2]
void rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    //transposing the matrix i.e row-> col  and col-> row
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
        swap(matrix[i][j], matrix[j][i]);
    }
    }

    //reversing each row of the matrix
    for (int i = 0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << "\n";
    }

}