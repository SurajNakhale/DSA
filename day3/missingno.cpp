

int missingarray(vector<int> a, int n){
    int size = a.size();

    for (int i=1; i<=n; i++){
        int flag = 0;
        for(int j=0; j<size; j++){
            if(a[j] == i){
               flag = 1;
               break;
            }
        }
        if(flag == 0) return i;
    }
}

int missingnumber(vector<int> &arr){
    int n = arr.size();

    int total = n*(n+1)/2;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += arr[i]
    }

    return total-sum;
    
}
int missingnumber(vector<int> &arr){
 int n = arr.size();
 int xor1=0;
 int xor2=0;

 for(int i=1; i<=n; i++){
    xor1 ^= i;
 }

 for(int i=0; i<n; i++){
    xor2 ^= arr[i];
 }

 return xor1^xor2;


}