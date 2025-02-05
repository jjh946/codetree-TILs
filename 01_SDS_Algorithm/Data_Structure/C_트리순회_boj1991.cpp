#include <iostream>

using namespace std;

int n;
char BTree[27][3];


void Visit (char node) {
    cout << node;
}

int Index(char node){
    for(int i=0;i<n;i++){
        if (BTree[i][0] == node) return i;
    }
    return -1;
}

void Preorder(char node) {
    if (node == '.'){
        return;
    }
    int index = Index(node);
    Visit(node);
    Preorder(BTree[index][1]);
    Preorder(BTree[index][2]);

}

void Inorder(char node) {
    if (node == '.'){
        return;
    }
    int index = Index(node);
    Inorder(BTree[index][1]);
    Visit(node);
    Inorder(BTree[index][2]);

}

void Postorder(char node) {
    if (node == '.'){
        return;
    }
    int index = Index(node);
    Postorder(BTree[index][1]);
    Postorder(BTree[index][2]);
    Visit(node);
}



int main() {
    
    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            cin >> BTree[i][j];
        }
    }

    // Visit('A');
    // cout << endl;
    Preorder('A');
    cout << endl;

    Inorder('A');
    cout << endl;

    Postorder('A');
    cout << endl;
    

    
    return 0;
}