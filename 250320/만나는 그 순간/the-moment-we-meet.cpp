#include <iostream>

using namespace std;

int n, m;
char d[1000];
int t[1000];
char d2[1000];
int t2[1000];

//정보 기록에는 배열 적극 활용

// *포인트: 가끔가다 이런 문제 자체에 쫄 때가 있다. 쉬운 문제이기 때문에 쫄지 말자
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> d[i] >> t[i];

    for (int i = 0; i < m; i++) cin >> d2[i] >> t2[i];

    // Please write your code here.
    int it=0, it2=0;
    int a=0, b=0;
    for(int sec=1;;sec++){
        if(t[it] <= 0){
            it++;
        }
        if(d[it]=='L'){
            a--;
        }
        else if(d[it] == 'R'){
            a++;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
        t[it]--;

        if(t2[it2] <= 0){
            it2++;
        }
        if(d2[it2]=='L'){
            b--;
        }
        else if(d2[it2]=='R'){
            b++;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
        t2[it2]--;

        if(a==b){
            cout << sec << endl;
            return 0;
        }
    }

    return 0;
}