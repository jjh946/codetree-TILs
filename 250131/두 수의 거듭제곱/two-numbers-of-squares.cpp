#include <iostream>

using namespace std;

// a^b의 값을 반환합니다.
int Power(int a, int b) {
    int cnt = 1;
    for(int i = 1; i <= b; i++)
        cnt *= a;

    return cnt;
}

int main() {
    // 변수 선언 및 입력:
    int a, b;
    cin >> a >> b;

    cout << Power(a, b);
    
    return 0;
}
