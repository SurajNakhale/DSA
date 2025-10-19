// Problem Statement: Given a matrix m X n, count paths 
// from left-top to the right bottom of a matrix with the
//  constraints that from each cell you can either only 
//  move to the rightward direction or the downward direction.

//better solution:
//base cases i>=n and j>=m return 0;
//i=n-1 and j=m-1 return 1;
//approaching with hash tree 

#include<bits/stdc++.h>
using namespace std;

// class solution {
//     public:

//     int countPaths(int i, int j, int n, int m){
//         if(i >= n || j >= m) return 0;
//         else if(i == n-1 && j == m-1) return 1;
//         else return countPaths(i+1, j, n, m)+countPaths(i, j+1, n, m);
//     }

//     int uniquePaths(int n, int m){
//         return countPaths(0,0,n,m);
//     }

// };


//better solutoin using dynamic solution: 
//repeating/doing  the w/o actually calling the function,
// we use dynamin hash table with -1 values if traversed change to 1,
//if change before if it is 1 leaves as it move on(skips one function call)

// class solution {
//     public: 
//         int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp){
//             if(i >= n || j >= m) return 0;
//             else if(i == n-1 && j == m-1) return 1;
//             else return dp[i][j] = countPaths(i+1, j, n, m, dp)+countPaths(i, j+1, n, m, dp);
//         }

//         int uniquePaths(int n, int m){
//             vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
//             int nums = countPaths(0,0,n,m,dp);
//             if(n==1 && m==1) return nums;
//             else return dp[0][0];
//         }
// };


//optimal soultion using pascal triangle algorithm nCr 
// we can find the total ono of ways by n-1 + m-1 = 2-1 + 3-1 = 1 + 2 = 3;
// NcR N=n+m-2 and R=n-1 OR R=m-1

class solution{
    public: 
            int uniquePaths(int n, int m){
                int N = n+m-2;
                int R = n-1;
                double res = 1;

                for(int i=1; i<= R; i++){
                    res = res * (N - R + i)/i;
                }

                return (int)res;
            }
};

int main(){
    solution obj;

    int totalcount = obj.uniquePaths(3,7);
    cout<<"Total Number of Unique Paths are: " << totalcount;

}