#include <iostream>

using namespace std;

int N, M, K;
int student[10000];
int cnt[101];

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        cin >> student[i];
        cnt[student[i]]++;
        if(cnt[student[i]]>=K){
            cout << student[i] << endl;
            return 0;
        }
    }


    return 0;
}