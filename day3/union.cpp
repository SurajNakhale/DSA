/*Union of two sorted arrays
Given two sorted arrays nums1 and nums2, return an array 
that contains the union of these two arrays. The elements in the union must be in ascending order.
The union of two arrays is an array where all values are distinct and \
are present in either the first array, the second array, or both.


Examples:
Input: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]

Output: [1, 2, 3, 4, 5, 7]

Explanation:

The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]

Output: [1, 3, 4, 5, 6, 7, 8, 9]

Explanation:

The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2*/

//brute for solution using set ;
//tc n1logn+n2logn+n1+n2  sc=>(n1+n2) + (n1+n2)[this extra aspace used to return the ans]
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        //brute force approach
        int n1 = nums1.size();
        int n2 = nums2.size();

        set<int> st;

        for(int i =0; i<n1; i++){
            st.insert(nums1[i]);
        }
        //tc=> n1logn sc=>n1
        for(int i=0; i<n2; i++){
            st.insert(nums2[i]);
        }
        //tc=> n2logn sc=>n2
        vector<int> ans;
        for(auto a : st){
            ans.push_back(a);
        }
        //tc=> n1+n2 sc=>n1+n2

        return ans;
    }
};

//optimal solution 
//using 2 pointer approach
//tc=> n1+n2
//sc=> n1+n2 us extra spce to display the union array other wise for the algorithm it is 0(1) is used
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        //brute force approach
       int n1 = nums1.size();
       int n2 = nums2.size();
       int i = 0;
       int j = 0;
       vector<int> unionAns;

       while(i<n1 && j<n2){
        if(nums1[i] <= nums2[j]){
            if(unionAns.size() == 0 || unionAns.back() != nums1[i]){
                unionAns.push_back(nums1[i]);
            }
            i++;
        }
        else{
            if(unionAns.size() == 0 || unionAns.back() != nums2[j]){
                unionAns.push_back(nums2[j]);
            }
            j++;
        }
       }

       while(j<n2){
         if(unionAns.size() == 0 || unionAns.back() != nums2[j]){
                unionAns.push_back(nums2[j]);
            }
            j++;
       }

       while(i<n1){
        if(unionAns.size() == 0 || unionAns.back() != nums1[i]){
                unionAns.push_back(nums1[i]);
            }
            i++;
       }
       return unionAns;
    }
};