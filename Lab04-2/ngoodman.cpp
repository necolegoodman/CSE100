//
//  main.cpp
//  Lab04-2
//
//  Created by Necole Goodman on 3/10/19.
//  Copyright © 2019 Necole Goodman. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Partition (int arr[], int p, int r){
    int x = arr[r];
    //int x = r;
    int i = p - 1;
            
            int temp;
            for(int j = p; j <= (r - 1); j++){
                if (arr[j] <= x){
                    i++;
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            temp = arr[i + 1];
            arr[i + 1] = arr[r];
            arr[r] = temp;
    
    return i + 1;
}
int Randomized_Partition(int arr[], int p, int r){
    //if (p < r){
       // int i = random(p ,r);
    srand(time(NULL));
    int total = (r - p + 1);
    int a = p + rand() % total;
    int temp;
    temp = arr[a];
    arr[a] = arr[r];
    arr[r] = temp;
    //arr[r] = arr[a];
    a = r;
    
    return Partition(arr, p, r);
}
void Quicksort (int arr[], int p, int r){
    if (p < r){
        int q = Randomized_Partition(arr, p , r);
        Quicksort(arr, p, q -1);
        Quicksort(arr, q + 1, r);
        }
    }
    
int main() {
    int arrLet;
    cin >> arrLet;
    
    int p = 0;
    int r = arrLet - 1;
    int arr[arrLet];
    
    for(int m = 0; m < arrLet; m++){
        cin >> arr[m];
    }
    
    Quicksort (arr, p, r);
    
    for (int k = 0; k < arrLet; k++){
        cout << arr[k] << ";";
    }
    
    return 0;
}
