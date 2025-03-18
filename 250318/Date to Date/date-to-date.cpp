#include <iostream>

using namespace std;

int main() {
    // 2011년의 각 월별 일 수
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int m1, d1, m2, d2;
    cin >> m1 >> d1 >> m2 >> d2;
    
    int totalDays = 0;
    
    // 같은 달 내에서의 날짜 계산
    if (m1 == m2) {
        totalDays = d2 - d1 + 1;
    } else {
        // 첫 번째 달의 남은 일 수 더하기
        totalDays += (daysInMonth[m1 - 1] - d1 + 1);
        
        // 중간의 모든 달 더하기
        for (int month = m1 + 1; month < m2; month++) {
            totalDays += daysInMonth[month - 1];
        }
        
        // 마지막 달의 일 수 더하기
        totalDays += d2;
    }
    
    cout << totalDays << endl;
    
    return 0;
}