#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    // Write your code here!
    int number = 0;
    for ( int i=0; i < N;i++){
        for(int j=0;j<N;j++){
            if (number<9){
                cout << ++number << ' ';
            }
            else{
                number = 1;
                cout << number << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}