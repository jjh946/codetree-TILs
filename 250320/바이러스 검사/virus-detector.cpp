#include <iostream>
using namespace std;

int n;
int rest[1000004];
int ldr, mbr;
int need;

int main() {
    // Please write your code here.
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