#include <iostream>
using namespace std;

int n;
int rest[1000004];
int ldr, mbr;
int need;

int main() {
    // cin / cout은 scanf / printf에 비해 속도가 느리므로, 
    // 입력받아야 할 개수가 많은 경우 다음 코드를 작성해줘야 합니다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);



    cin >> n;
    for(int i=1;i<=n;i++) cin >> rest[i];
    cin >> ldr >> mbr;

    for(int i=1;i<=n;i++){
        int nam;
        if(rest[i]>ldr){
            nam = rest[i] - ldr;
            if(nam % mbr==0){
                need += 1 + nam / mbr;
            }
            else{
                need += 1 + (nam/mbr +1);
            }
        }
        else{
            need++;
        }
    }
    cout << need << endl;

    return 0;
}