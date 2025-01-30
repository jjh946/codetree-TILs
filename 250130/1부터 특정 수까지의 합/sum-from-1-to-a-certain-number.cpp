#include <iostream>

using namespace std;

int N;

int Function(int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += i+1;
    }
    return sum/10;

}


int main() {
    cin >> N;

    // Write your code here!
    cout << Function(N);
    return 0;
}