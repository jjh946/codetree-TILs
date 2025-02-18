#include <iostream>

using namespace std;

int n, m;
int A[100004];
// long long dp[100004][100004]; 너무 큰 메모리를 사용함. 세그멘트 폴트 나옴
// int dp[100004][100004]; 이 방식은 내 컴퓨터에서는 해결이 됐지만 백준에서 터짐
//100004 × 100004 × 4 bytes = 약 40TB 😱
//현대 컴퓨터에서 이런 크기의 배열을 사용할 수 없음 → 메모리 초과로 강제 종료

long long prefixSum[100004]; // 1차원 방식의 '누적합' 사용

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for(int k=1;k<=n;k++) {
        cin >> A[k];
        prefixSum[k] = prefixSum[k-1] + A[k];
    } 
    

    for(int k=1;k<=m;k++){
        int i, j;
        cin >> i >> j;
        cout << prefixSum[j] - prefixSum[i-1] << '\n';
    }

    return 0;
}