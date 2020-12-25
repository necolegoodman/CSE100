//
//  main.cpp
//  lab2
//
//  Merge Sort
//  Created by Necole Goodman on 2/13/19.
//  Copyright © 2019 Necole Goodman. All rights reserved.
//

#include <iostream>

using namespace std;

void MergeSort (int * arr[], int q, int p, int r) {
    
    int i , j;
    int ArraySize = 1;

    //int * arr = new int[i];
    cin >> ArraySize;
    
    int n1 = q - p + 1; // L[1..n1 + 1]
    int n2 = r - q; // R[1..n2 + 1]
    
    int * L = new int[n1 + 1]; //creating the two arrays?
    int * R = new int[n2 + 1];
    
    for (int i; i < n1; i++){
        L[i] = *arr[q + 1];
    }
    for (int j = 0; j < n2; j++){
        R[j] = *arr[p + j + 1];
    }
    
    /*void MergeSort (int * arr[], int p, int r){
    if (p < r){
        q = (p + r)/2;
    }
    MergeSort (int * arr[], int p, int q)
    MergeSort (int * arr [], int q + 1, r)
    MergeSort (int * arr[], int p, int q, int r) */
    }
    



