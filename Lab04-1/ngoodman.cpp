#include <iostream>
using namespace std;

void Max_Heapify (int arr[], int i, int arraysize){
    int temp, Max;
    
    Max = i;
    int left = (2 * i);
    int right = ((2 * i) + 1);
    
    if ((left <= arraysize) && (arr[left] > arr[Max])){
        Max = left;
    }
   // else{
       // Max = i;
   // }

    if ((right <= arraysize)&& (arr[right] > arr[Max])){
    Max = right;
}
    if (Max != i){
        temp = arr[i];
        arr[i] = arr[Max];
        arr[Max] = temp;
        Max_Heapify (arr, Max, arraysize);
    }
}

    void Build_Max_Heap (int arr[], int arraysize){
        for(int j = (arraysize / 2); j >= 1; j--){
            Max_Heapify (arr, j, arraysize);
        }
    }
    void HeapSort (int arr[], int arraysize) {
        Build_Max_Heap(arr, arraysize);
        int temp;
        
        for(int i = arraysize; i >= 2; i--){
            temp = arr [1];
            arr[1] = arr[i];
            arr[i] = temp;
            Max_Heapify (arr, 1, i - 1);
    }
    
    }
    
int main () {
    int arraysize;
    cin >> arraysize;
    int arr[arraysize];
    
    for(int i = 1; i <= arraysize; i++){
        cin >> arr[i];
    }
    
    HeapSort(arr, arraysize);
    for (int k = 1; k <= arraysize; k++){
        cout << arr[k] << ";";
}
    return 0;
}

