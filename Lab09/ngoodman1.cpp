#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

string HuffmanEncodings[100];

/* HUFFMAN.C /
 1 n D jCj
 2 Q D C
 3 for i D 1 to n   1
 4 allocate a new node ´
 5 ´:left D x D EXTRACT-MIN.Q/
 6 ´:right D y D EXTRACT-MIN.Q/
 7 ´:freq D x:freq C y:freq
 8 INSERT.Q; ´/
 9 return EXTRACT-MIN.Q/ // return the root of the tree*/
struct Node { //using pseduo code from book
    Node* left; // creating left child
    Node* right;// right child
    string letter;
    int frequency; // need frequency
    int unique_id;
    
    Node(string letter, int frequency) {
        left = NULL;
        right = NULL;
        this->letter = letter;
        this->frequency = frequency;
        this->unique_id = 0;
    }
    
    Node(string letter, int frequency, int unique_id) {
        left = NULL;
        right = NULL;
        this->letter = letter;
        this->frequency = frequency;
        this->unique_id = unique_id;
    }
};

struct compare {
    bool operator() (Node* left, Node* right) {
        if(left->frequency == right->frequency)
            return (left->unique_id > right->unique_id);
        else
            return (left->frequency > right->frequency);
    }
};


void printEncodings(Node* minHeapRoot, string encondings, string alphabet[], int size) {
    
    if(minHeapRoot == NULL) {
        return;
    }
    else {
        
        if(minHeapRoot->letter.compare("$") != 0) { // compares symbols to see if its a destination
            for (int i = 0; i < size; i++) {
                if(minHeapRoot->letter.compare(alphabet[i]) == 0) {
                    HuffmanEncodings[i] = encondings;
                }
            }
        }
        
        if(minHeapRoot->letter.compare("$") == 0) { //compares symbols to see if its a path
            printEncodings(minHeapRoot->left, encondings + "0", alphabet, size);
            printEncodings(minHeapRoot->right, encondings + "1", alphabet, size);
        }
    }
}

void HuffmanEncode(int size, string alphabet[], vector<int>& C) { //Huffman code from the algo book
    
    priority_queue<Node*, vector<Node*>, compare> HuffmanHeap; //priority que automatically sorts in min priority
    
    Node* root = NULL; //intiliazing to null
    Node* left = NULL;
    Node* right = NULL;
    
    for (int i = 0; i < size; i++) {
        Node* temp = new Node(alphabet[i], C[i], i + 1);
        HuffmanHeap.push(temp);
    }
    
    
    while(HuffmanHeap.size() > 1) {
        
        left = HuffmanHeap.top(); //extracts the min
        HuffmanHeap.pop();
        
        right = HuffmanHeap.top();
        HuffmanHeap.pop();
        
        Node* newParent = new Node("$", (left->frequency + right->frequency));
        root = newParent;
        if(left->frequency == right->frequency && left->unique_id > right->unique_id) {
            root->left = right;
            root->right = left;
            root->unique_id = right->unique_id;
        }
        else {
            root->left = left;
            root->right = right;
            root->unique_id = left->unique_id;
        }

        HuffmanHeap.push(root);
    }
    printEncodings(HuffmanHeap.top(), "", alphabet, size);
    
    
    for (int i = 0; i < size; i++) {
        cout << HuffmanEncodings[i] << endl;
    }
}


int main(int argc, char** argv) { //consulted with friends on priority que and main func
    
    int size = 0;
    int value = 0;
    
    
    cin >> size;
    
    vector<int> freq;
    string alphabet[size];
    
    for (int i = 0; i < size; i++) {
        cin >> value;
        freq.push_back(value);
        alphabet[i] = "K" + to_string(i);
    }
    
    
    HuffmanEncode(size, alphabet, freq);

    
    
    return 0;
}