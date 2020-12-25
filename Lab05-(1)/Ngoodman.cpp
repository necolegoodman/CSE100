//radix sort
#include <iostream>
#include <vector>
#define k 10 //fixed length of vector is k = 10

using namespace std;


vector< vector< int> > countSort(vector < vector<int> > A, vector<int> C)
{
    vector< vector<int> > B;
    vector<int> D(k,0);
    B.resize(C.size());
    
    for (int j = 0; j < C.size(); j++) {
        D[C[j]]++;
    }
    for (int i = 1; i < D.size(); i++) {
        D[i] += D[i-1];
    }
    for (int j = 0; j < C.size(); j++) {
        B[j].resize(k);
    }
    for (int i = C.size() - 1; i >= 0 ; i--) {
        swap(B[D[C[i]]-1], A[i]);
        D[C[i]] =  D[C[i]] -  1;
    }
    return B;
}
void print(vector < vector<int> > A)
{
    for(int i = 0; i < A.size(); i++){
        for (int j = 0; j < A[i].size(); j++){
            cout << A[i][j] << ";";
        }
        cout << endl;
    }
}

void radixSort(vector < vector<int> > A)
{
    for (int i = 9; i >= 0; i--) {
        vector<int> C;
        for (int j = 0; j < A.size(); j++ )
            C.push_back(A[j][i]);
        A = countSort(A,C);
    }
    print(A);
    
}

void ask(vector < vector<int> > A)
{
    int size;
    int value;
    
    //    cout << "What is the size of your original array? ";
    cin >> size;
    A.resize(size);
    
    //    cout << "What is your array elements? ";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < k; j++) {
            cin >> value;
            A[i].push_back(value);
        }
    }
    radixSort(A);
}

int main(int argc, const char * argv[]) {
    vector < vector< int > > A;
    ask(A);
    return 0;
}
