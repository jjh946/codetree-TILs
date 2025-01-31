#include <iostream>
#include <cmath>

using namespace std;

// 거듭제곱을 계산하고 출력하는 함수
void printPower(int a, int b) {
    cout << pow(a, b) << endl;
}

int main() {
    int a, b;
    cin >> a >> b; // 두 정수 입력 받기
    printPower(a, b); // 함수 호출하여 결과 출력
    return 0;
}
