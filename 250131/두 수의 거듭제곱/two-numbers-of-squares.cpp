#include <iostream>

using namespace std;

int a, b;

double Easy(int a, int b){
    int answer = 1;
    for(int i=0;i<b;i++){
        answer *= a;
    }
    return answer;
}

int main() {
    cin >> a >> b;

    // Write your code here!
    cout << Easy(a,b);

    return 0;
}