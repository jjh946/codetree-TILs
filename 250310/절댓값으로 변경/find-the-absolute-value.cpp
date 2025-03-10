#include <iostream>

using namespace std;

int n;
int arr[50];

void func(int lst[]){
    for (int i = 0; i < n; i++){
        if(lst[i]<0){
            lst[i] = 0 - lst[i];
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Please write your code here.
    func(arr);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}