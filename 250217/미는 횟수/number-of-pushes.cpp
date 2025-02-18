#include <iostream>
#include <string>

using namespace std;

string A,B;

int main () {

    cin >> A >> B;
    
    int i;
    for(i=1;i<=B.size();i++){
        //밀어내기
        B = B + B[0];
        B.erase(0,1);

        //cout << B << endl;

        if(A==B){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}