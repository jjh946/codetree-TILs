#include <iostream>
#include <vector>
using namespace std;

int K, N;

vector<int> sequence; // 현재까지 만든 수열을 저장할 벡터

void backtrack (int depth) {
    // 완성 조건: 선택 횟수가 n번이면 해 출력
    if (depth == N) {
        //수열 출력
        for (int i = 0; i<N; i++){
            cout << sequence[i] << ' ';
        }
        cout << "\n";
        return;
    }

    // 1부터 K까지 시도 
    for (int num = 1; num <= K; num++){
        sequence.push_back(num); // 후보 추가
        backtrack(depth + 1); // 다음 깊이로 진행
        sequence.pop_back();  // 백트래킹: 마지막 선택 제거
    }
}


int main() {
    cin >> K >> N;

    // backtracking 써서 풀긴 해야겠지
    //그거 어떻게 

    backtrack(0);

    return 0;
}
