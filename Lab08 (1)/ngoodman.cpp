#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int** m; //initializing variables
int** s;

void Print(int i, int j){
    //i = i - 1;
    //j = j - 1;
    if(i == j)
        cout << "A" << i - 1;
    else{
        cout << "(";
        Print(i, s[i][j]);
        Print(s[i][j]+1, j);
        cout << ")";
    }
}


void MatrixChainOrder(int* Array, int arraySize){
    int i, l, j, k, q;
    int n = arraySize + 1;
    m = new int*[n]; //makes rows
    for(int i = 0; i <= n; i++) {//makes columns
        m[i] = new int[n];
    }
    s = new int*[n]; //makes rows
    for(int i = 0; i <= n; i++) {//makes columns
        s[i] = new int[n];
    }
    
    for(i = 1; i < n; i++){
        m[i][i] = 0;
    }
    for(l = 2; l < n; l++){ //2
        for(i = 1; i < n-l+1; i++){//1
            j = i + l - 1;
            m[i][j] = 1000000;
            for(k = i; k <= j-1; k++){
                q = m[i][k] + m[k+1][j] + Array[i-1]*Array[k]*Array[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n-1] << endl;
    Print(1, n-1);
    cout << endl;
    
}


int main(int argc, const char * argv[]) {
    int* Sequence;
    int arraySize;
    
    cin >> arraySize;
    
    Sequence = new int[arraySize + 2];
   
    
    for(int i = 0; i < arraySize + 1; i++){
        cin >> Sequence[i];
    }
    
    MatrixChainOrder(Sequence, arraySize);
}


