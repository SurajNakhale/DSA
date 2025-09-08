// intersection of array
/*
a[] = {1,2,2,3,3,4,5,6}
b[] = {2,3,3,5,6,6,7};

ans[] = {2,3,3,5,6}

*/

// brute force approach
//solving using visited array initially it will be containing 0 values;

vector<int>  intersection(vector<int>&num1, vector<int>&num2){
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> ans;
    vector<int> vis(n2, 0);

    for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(nums[i] == nums[j] && vis[j]==0){
              ans.push_back(num[i]);
              vis[j] = 1;
              break;
            }
            if(num2[j] > num1[i]) break;
        }
    }

    return ans;
}


//optimal solution
vector<int> intersection (vector<int>&nums1, vector<int> &nums2){
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i=0;
    int j=0;
    
    while(i<n1 && j<n2){
        if(nums1[i] == nums2[j]){
            ans.push_back(nums1[i]);
            i++;
            j++;
        }else if(nums1[i] < nums2[j]){
            i++;
        }else{
            j++;
        }
    }
    return ans;
    

}