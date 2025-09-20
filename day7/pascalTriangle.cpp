/*
Problem Statement: This problem has 3 variations. They are stated below:

// Variation 1: Given row number r and column number c. 
// Print the element at position (r, c) in Pascal’s triangle.

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle
*/



/*example
Example 1:
Input Format: N = 5, r = 5, c = 3
Result: 6 (for variation 1)
1 4 6 4 1 (for variation 2)

1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1    (for variation 3)

Explanation: There are 5 rows in the output matrix. 
Each row is formed using the logic of Pascal’s triangle.
*/


// Variation 1: Given row number r and column number c. 
// Print the element at position (r, c) in Pascal’s triangle.


#include<bits/stdc++.h>
using namespace std;


// int ncr(int n, int r){
    // long long res = 1;

    // for(int i=0; i<r; i++){
    //     res = res*(n-i);
    //     res = res/(i+1);
    // }
    // return res;

// }

// int pascalTriangle(int r, int c){
//     int element  = ncr(r-1, c-1);
//     return element;
// }

// int main(){
//     int r = 5;
//     int c = 3;
//     int element = pascalTriangle(r, c);
//     cout << element;

// }


// Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.
// int ncr(int n, int r){
//     long long res = 1;

//     for(int i=0; i<r; i++){
//         res = res*(n-i);
//         res = res/(i+1);
//     }
//     return res;
// }

// int generateRow(int n){
//     for(int c=1; c<=n; c++){
//         cout<< ncr(n-1, c-1)<<" ";
//     }
// }


//optimal approach

// int generateRow(int n){
//     long long ans = 1;
//     cout<< ans<<" ";

//     for(int i =1; i<n; i++){
//         ans = ans*(n-i);
//         ans = ans/i;
//         cout << ans<< " ";
//     }

// }
// int main(){

//     int n =5;
//     generateRow(n);
//     return 0;
// }


//variation 3: print whole pascal triangle 

vector<int> generate(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);

    for(int col = 1; col<row; col++){
        ans = ans * ( row-col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;

}
vector<vector<int>> pascalTriangle(int n){
  vector<vector<int>> ans;
  for(int row = 1; row<=n; row++){
    ans.push_back(generate(row));
  }
  return ans;

}
int main(){
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for(auto it : ans){
        for(auto ele : it){
            cout << ele << " ";
        }
        cout<<"\n";
        
    }
    return 0;
}