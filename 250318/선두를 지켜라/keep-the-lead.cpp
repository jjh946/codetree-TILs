#include <bits/stdc++.h>
using namespace std;

/**
 * (posA, posB): 현재 시점에서 A, B의 위치
 * oldLeader   : 이전 리더 (0=아직 없음/동점, 1=A, 2=B)
 * 리턴값      : 새 리더 (동점이면 oldLeader 유지)
 */
int getLeader(double posA, double posB, int oldLeader) {
    const double EPS = 1e-12;
    if (fabs(posA - posB) < EPS) {
        // 위치가 거의 같으면 (동점)
        return oldLeader; 
    }
    else if (posA > posB) {
        return 1; // A가 앞섬
    }
    else {
        return 2; // B가 앞섬
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // A의 (속도, 시간) 구간
    vector<pair<double,double>> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i].first >> A[i].second; 
    }

    // B의 (속도, 시간) 구간
    vector<pair<double,double>> B(M);
    for(int i = 0; i < M; i++){
        cin >> B[i].first >> B[i].second; 
    }

    // 위치, 리더 정보
    double posA = 0.0, posB = 0.0; 
    int oldLeader = 0;    // 0=동점/미정, 1=A, 2=B
    int leadChanges = 0;  // 선두 바뀐 횟수

    // 현재 진행 중인 구간 인덱스
    int i = 0, j = 0;
    // 각 구간에서 '남은 시간' (처음엔 입력값 그대로)
    double remainA = A[0].second; 
    double remainB = B[0].second;
    double speedA  = A[0].first;
    double speedB  = B[0].first;

    // 시뮬레이션
    while(i < N && j < M){
        // 이번에 처리할 시간 (두 구간 중 더 빨리 끝나는 쪽)
        double dt = min(remainA, remainB);

        // posA, posB가 구간 시작 시점에서의 위치
        double startA = posA;
        double startB = posB;

        // speeds가 같지 않다면, 그 구간 안에서 교차(추월) 시점이 있는지 확인
        // posA(t) = startA + speedA * t
        // posB(t) = startB + speedB * t
        // 교차조건: startA + speedA*t = startB + speedB*t  =>  t = (startB - startA) / (speedA - speedB)
        double crossingTime = -1.0;
        const double EPS = 1e-12;

        if (fabs(speedA - speedB) > EPS) {
            double tC = (startB - startA) / (speedA - speedB);
            // tC가 0 < tC < dt 이면 그 구간 안에서 교차 발생
            if (tC > 0.0 && tC < dt) {
                crossingTime = tC;
            }
        }

        // 이제 세 가지 경우를 순서대로 처리
        // (1) 교차가 없는 경우, (2) 교차가 dt의 범위 밖인 경우 => 한 덩어리로 처리
        // (3) 교차가 구간 내에 있는 경우 => 교차 시점까지, 그리고 그 이후로 나누어 2번 처리
        if (crossingTime < 0.0) {
            // 교차가 없거나 (0, dt) 범위에 들지 않음 => 전체 dt 동안 그냥 이동
            posA += speedA * dt;
            posB += speedB * dt;

            // 새 리더 판단
            int newLeader = getLeader(posA, posB, oldLeader);
            // 리더가 바뀌었으면 카운트
            if (newLeader != oldLeader && newLeader != 0) {
                // oldLeader=0(처음) -> newLeader=1 or 2 도 포함
                if (oldLeader != 0) {
                    leadChanges++;
                }
                oldLeader = newLeader;
            }
            // 이 dt 소모
            remainA -= dt;
            remainB -= dt;
        }
        else {
            // 교차가 구간 내 (0, dt)에 존재
            // 1) 교차 시점 crossingTime 까지 이동
            posA = startA + speedA * crossingTime;
            posB = startB + speedB * crossingTime;

            // 교차 직전까지의 리더 갱신
            int newLeader = getLeader(posA, posB, oldLeader);
            if (newLeader != oldLeader && newLeader != 0) {
                if (oldLeader != 0) {
                    leadChanges++;
                }
                oldLeader = newLeader;
            }

            // crossingTime 만큼 소모
            remainA -= crossingTime;
            remainB -= crossingTime;
            dt -= crossingTime;  // 남은 dt (교차 이후 처리)

            // 2) 교차 시점 이후 ~ dt까지 이동
            // 교차 직후에도 속도는 같음 (segment가 안 바뀌었다면)
            double startA2 = posA;
            double startB2 = posB;
            posA = startA2 + speedA * dt;
            posB = startB2 + speedB * dt;

            // 교차 이후의 리더 갱신
            newLeader = getLeader(posA, posB, oldLeader);
            if (newLeader != oldLeader && newLeader != 0) {
                if (oldLeader != 0) {
                    leadChanges++;
                }
                oldLeader = newLeader;
            }

            remainA -= dt;
            remainB -= dt;
        }

        // 만약 A의 구간이 끝났다면 다음 구간으로
        if (fabs(remainA) < EPS) {
            i++;
            if (i < N) {
                remainA = A[i].second;
                speedA  = A[i].first;
            }
        }
        // B의 구간이 끝났다면 다음 구간으로
        if (fabs(remainB) < EPS) {
            j++;
            if (j < M) {
                remainB = B[j].second;
                speedB  = B[j].first;
            }
        }
    }

    // 시뮬레이션 종료
    cout << leadChanges << "\n";
    return 0;
}