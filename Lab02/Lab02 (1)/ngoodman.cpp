#include <iostream>
#include <climits>
using namespace std;

void Merge(int arr[], int p, int q, int r){
    int i=0,j=0;
    int k;
    //int ArraySize = 1;
   // cin >> ArraySize;
    int n1 = q - p + 1;
    int n2 = r - q;
    
    //create a temp array to store elements for left and right-hand side
    int L[n1+1]; // left-hand side
    for(int i = 0; i < n1; i++){
        L[i] = arr[p+i];
    }
    int R[n2+1]; // right hand side
    for (int j = 0; j<n2; j++){
        R[j] = arr[q+j+1];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    //function to compare and merge the two sides into the temp array
    for (k = p; i < n1 || j < n2; k++){
        if(L[i] < R[j]){
            arr[k] = L[i++];
        }
        else {
            arr[k] = R[j++];
        }
    }
}

void Mergesort(int arr[], int p, int r){
    int q;
    if (p < r){
        q =((p+r)/2);
        Mergesort(arr,p,q);
        Mergesort(arr, q+1, r);
        Merge(arr,p,q,r);
    }
}

int main () {
    int n,i, *arr;
    cin >> n;

    arr = new int[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Mergesort(arr, 0, n-1);
    
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ';';
    }

    delete[] arr;
    return EXIT_SUCCESS;
}
    

