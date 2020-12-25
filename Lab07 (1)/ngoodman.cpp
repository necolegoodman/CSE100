//
//  main.cpp
//  lab7
// CutRod
//  Created by Necole Goodman on 3/20/20.
//  Copyright © 2020 Necole Goodman. All rights reserved.
//
//#include <tuple>
#include <iostream>
using namespace std;

/*int CutRod(int * p, int n){
    if(n == 0){
        return 0;
    }
   int q = INT_MIN;
    for(int i = 1; i <= n; i++){
        int q = max(q,p[i] + CutRod(p,n-i));
    }
    return q;
    }
   
   MemoizedCutRod(int p, int n){
        int r[];
        for(int i = 0; i <= n; i++){
            r[i] = -INFINITY;
        }
        return MemoizedCutRodAux(p,n,r);
    }
    
    MemoizedCutRodAux(int p[], int n, int r){
        if (r[n] >= 0){
            return r[n];
        }
        if (n == 0){
            int q = 0;
        }else{
            q = -INFINITY;
        }
        for (int i = 1, i <= n; i++){
            q = max(q,p[i] + MemoizedCutRod(p, n-i,r))
            r[n] = q;
            return q;
        }
    }
    
    BottomUpCutRod(int p, int n){
        int r[0]=0;
        for (int j = i; j <= n; j++){
            q = -INFINITY;
            for (int i = 1; i <= j; i++){
                q = max(q,p[i] + r[j - i])
                r[j] =  q;
            }
            return r[n];
        }
    */
int ExtendedBottomCutRod(int *p, int n){
    int i,j;
           int *r = new int[n + 1];
           int *s = new int[n + 1];
           r[0] = 0;
           

           for(int j = 1; j <= n; j++){
                int q = -2147483647;
                int x = -1;
                for (int i = 1; i <= j; i++){
                    if(q < p[i] + r[j - i]){
                        q = p[i] + r[j - i];
                        //s[j] = i;
                        x = i;
                    }
                }
                //return make_tuple (r,s);
               r[j] = q;
               s[j] = x;

            }
    
        cout << r[n] << endl;
       
    
   while (n > 0) {
          cout << s[n] << " ";
          n = n - s[n];
      }
    
      cout << "-1" <<endl;
     //return make_tuple (r,s);*/
    return 0;
}
    /*void PrintCutRod(int *p, int n){
    //(r,s) = ExtendedBottomCutRod(p,n);
        while (n > 0){
            cout << p[n] << " ";
           // print s[n];
            n = n - p[n];
        }
        cout << "-1" << endl;
    }*/

int main(int argc, char ** argv) {
    int *sequence;
    int n;
    
    cin >> n;
    sequence = new int[n + 1];
    sequence[0] = 0;
    
    /*int *s = new int[n + 1];
    int *r = new int[n + 1];*/
    
    for(int i = 1; i <= n; i++){
        cin >> sequence[i];
        
        //cout << CutRod(sequence, n) << endl;
        /*tie(r,s) = */
        
    }
    ExtendedBottomCutRod(sequence,n);
    //PrintCutRod(r,n);
    return 0;
    }
