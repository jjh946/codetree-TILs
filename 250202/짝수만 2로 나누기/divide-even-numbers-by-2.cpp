#include <iostream>

using namespace std;

int n;
int arr[50];

void f(int *arr){
    for(int i=0; i<n; i++){
        if (arr[i]%2==0){
            arr[i] /= 2;
        }
        cout << arr[i] << ' ';
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Write your code here!
    f(arr);

    return 0;
}