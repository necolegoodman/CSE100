//
//  main.cpp
//  Lab 3
//
//  Created by Necole Goodman on 2/15/20.
//  Copyright © 2020 Necole Goodman. All rights reserved.
//

#include <iostream>
#include <tuple>

using namespace std;


tuple <int, int, int> FindMaxCrossing(int* arr, int low, int med, int high){
  
    int maxLeft, maxRight;
    int i, j;
    int leftSum = -1000000;
    int sum = 0;
    
    for(i = med; i >= low; i--){
        sum = sum + arr[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }
    
    int rightSum = -1000000;
    sum = 0;
    
    for(j = med+1; j <= high; j++){
        sum = sum + arr[j];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = j;
        }
    }
    
    return make_tuple(maxLeft, maxRight, (leftSum + rightSum));
    }
  

tuple<int, int, int> FindMaxSubArray(int* arr, int low, int high ){
    int med;
    
    int leftLow, leftHigh, leftSum, rightLow, rightHigh, rightSum, crossLow, crossHigh, crossSum;
    
    
   if (high == low){
            return make_tuple(low, high, arr[low]);
        }
        
            med = (low + high)/2;
            tie(leftLow, leftHigh, leftSum) = FindMaxSubArray(arr, low, med);
            tie(rightLow, rightHigh, rightSum) = FindMaxSubArray(arr, med+1, high);
            tie(crossLow, crossHigh, crossSum) = FindMaxCrossing(arr,low, med, high);
        
        if (leftSum >= rightSum && leftSum >= crossSum){
            return make_tuple(leftLow, leftHigh, leftSum);
        }
        else if (rightSum >= leftSum && rightSum >= crossSum){
            return make_tuple(rightLow, rightHigh, rightSum);
        }
        else{
            return make_tuple(crossLow, crossHigh, crossSum);
        
    }
    }
    
   int main(int argc,char **argv) {
        
        int i;
        int arraySize;
        int* Sequence;
        int num1, num2, num3;
        
        
        cin >> arraySize;
        Sequence = new int[arraySize];
        
        for(i = 0; i < arraySize; i++)
            cin >> Sequence[i];
        
        tie(num1, num2, num3) = FindMaxSubArray(Sequence, 0, arraySize-1);
        cout << num3;
        return 0;

    }

