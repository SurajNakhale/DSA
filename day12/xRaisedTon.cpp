/*
Example 1:

Input: x = 2.00000, n = 10
Output: 1024.00000
Example 2:

Input: x = 2.10000, n = 3
Output: 9.26100
Example 3:

Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25


Brute force approach 

Approach:  Looping from 1 to n and keeping a ans(double) variable. 
    Now every time your loop runs, multiply x with ans. At last, we will return the ans.

Now if n is negative we must check if n is negative, if it is negative divide 1 by the and.*/


#include<bits/stdc++.h>
using namespace std;

double pow(double x, int n){
    double ans = 1.0;

    long long nn = n;
    if(nn < 0) nn = -nn;

    while(nn){
        if(nn%2){//for odd n
            ans = ans * x;
            nn = nn - 1;
        }
        else{
            x = x * x;
            nn = nn/2;

        }

    }
    if(n<0) ans = (double) 1.0/ (double) ans;
    return ans;
    
}
int main(){
    double x = 2;
    int n = 10;

    double result = pow(x,n);

    cout<<"Result:" << result;
}