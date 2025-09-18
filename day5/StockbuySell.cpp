// Best time to buy and sell stock

// Given an array arr of n integers, where arr[i] 
// represents price of the stock on the ith day. Determine 
// the maximum profit achievable by buying and selling the stock at most once. 


// The stock should be purchased before selling it, 
// and both actions cannot occur on the same day.

/*Examples:
Input: arr = [10, 7, 5, 8, 11, 9]

Output: 6

Explanation: Buy on day 3 (price = 5) and
sell on day 5 (price = 11), profit = 11 - 5 = 6.*/

//solution:
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> a, int n){
    int profit = 0;
    int mini = a[0];

    for(int i = 0; i<n; i++){
        int cost = a[i] - mini;

        profit = max(profit, cost);
        mini = min(mini, a[i]);
    }
    return profit;
}

int main(){
    vector<int> a = {10, 7, 5, 8, 11, 9};
    int n = a.size();

    int ans = maxProfit(a, n);
    cout<< ans;
}