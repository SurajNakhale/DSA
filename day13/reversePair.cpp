//give arr of int find the no of pair left ele should
// be greater than twice of right ele
//a[i] > 2*arr[j] (6,2)

//brute force approach:
#include<bits/stdc++.h>
using namespace std;
int Pair(vector<int> &a, int n){
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i]>2*a[j]){
                cnt++;
            }
        }
    }
    return cnt;
}

//optimal soultion code:
void merge(vector<int> &a, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;

    //sorting element in temp array in sorted manner
    while(left<=mid && right<=high){
        if(a[left] <= a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
    }

    //if element on the left half are still left
    while(left<=right){
        temp.push_back(a[left]);
        left++;
    }

    //if element of right half is still left
    while(right<=high){
        temp.push_back(a[right]);
        right++;
    }

    //transfering all element from the temp array to the actual array
    for(int i=low; i<=high; i++){
        a[i] = temp[i-low];
    }
}


int countPairs(vector<int> &a, int low, int mid, int high){
    int right = mid+1;
    int cnt = 0;
    for(int i=low; i<=mid; i++){
        while(right <= high && a[i]>2*a[right]) right++;
        cnt += (right -(mid+1));
    }
    return cnt;
}

int mergeSort(vector<int>&a, int low, int high){
    int cnt =0; 
    if(low >= high) return cnt;
   
    int mid  =(low +high)/2;

    cnt += mergeSort(a, low, mid); //left half
    cnt += mergeSort(a, mid +1, high); //right half
    cnt += countPairs(a, low, mid, high);
    merge(a, low, mid, high);
    return cnt;


}
int PairOptimal(vector<int> &a, int n){
    return mergeSort(a, 0, n-1);
}

int main(){
    int n = 5;
    vector<int> a = {4, 1, 2, 3, 1};

    // int cnt = Pair(a, n);
    int cntop = PairOptimal(a, n);
    // cout<<"number of reverse pair are: "<< cnt <<"\n";
    cout<<"number of reverse pair are: "<< cntop;

}