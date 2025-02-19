#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T, n;
int cards[1002];
int dp[1002][1002];

// 근우가 얻을 수 있는 최대 점수를 반환
int D(int left, int right, int turn) {
    // 카드 범위를 벗어난 경우
    if (left > right) return 0;

    // 이미 계산된 경우
    if (dp[left][right] != -1) return dp[left][right];

    // 근우 차례일 때
    if (turn % 2 == 1) {
        return dp[left][right] = max(cards[left] + D(left + 1, right, turn + 1),
                                     cards[right] + D(left, right - 1, turn + 1));
    }
    // 명우 차례일 때
    else {
        return dp[left][right] = min(D(left + 1, right, turn + 1), 
                                     D(left, right - 1, turn + 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> cards[i];
        }

        // DP 배열 초기화
        memset(dp, -1, sizeof(dp));

        // 근우가 얻을 수 있는 최대 점수 출력
        cout << D(1, n, 1) << "\n";
    }

    return 0;
}