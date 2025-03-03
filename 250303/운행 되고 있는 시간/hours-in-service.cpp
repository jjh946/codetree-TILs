#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> developers(N);
    vector<int> work(1001, 0); // 1~1000까지의 시간 관리

    // 개발자들의 근무 시간 입력
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        developers[i] = {A, B};

        // 근무 시간 표시
        for (int t = A; t < B; t++) {
            work[t]++;
        }
    }

    // 전체 운영되고 있는 시간 계산
    int total_runtime = 0;
    for (int t = 1; t <= 1000; t++) {
        if (work[t] > 0) total_runtime++;
    }

    // 한 명을 해고했을 때 최대 운영 시간을 계산
    int max_runtime = 0;
    for (int i = 0; i < N; i++) {
        int A = developers[i].first;
        int B = developers[i].second;

        // 해당 개발자의 시간 제거
        for (int t = A; t < B; t++) {
            work[t]--;
        }

        // 새로운 운영 시간 계산
        int new_runtime = 0;
        for (int t = 1; t <= 1000; t++) {
            if (work[t] > 0) new_runtime++;
        }

        // 최대 운영 시간 갱신
        max_runtime = max(max_runtime, new_runtime);

        // 제거한 개발자의 시간 복원
        for (int t = A; t < B; t++) {
            work[t]++;
        }
    }

    cout << max_runtime << endl;

    return 0;
}