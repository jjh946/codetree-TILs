#include <iostream>

using namespace std;

int n1, n2;
int a[100], b[100];

bool IsSeqSubSet(int a[],int b[]){
    for (int i = 0; i<n1; i++){
        if (a[i]==b[0]){
            for (int j=1; j<n2; j++){
                if(a[i+j]!=b[j]) return false;
            }
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2;

    for (int i = 0; i < n1; i++) cin >> a[i];

    for (int i = 0; i < n2; i++) cin >> b[i];

    // Write your code here!

    if (IsSeqSubSet(a,b)) cout << "Yes";
    else cout << "No";


    return 0;
}