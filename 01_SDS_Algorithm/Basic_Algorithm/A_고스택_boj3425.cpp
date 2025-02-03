#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
long long stack[1001];
char inst[100001][5];
long long nums[100001];

int main(){

    while(1){

        for(int i = 0;;i++){
            cin >> inst[i];
            //여기서 strcmp를 쓰는 것은 생각하지 못했다. str을 비교하는 함수다.
            if (strcmp(inst[i], "QUIT") == 0) return 0;
            if (strcmp(inst[i],"END") == 0) break;
            if (strcmp(inst[i], "NUM") == 0){
                cin >> nums[i];
            }
        }
        cin >> n;
        for (int i=0;i<n;i++){
            cin >> stack[0];
        }
        

    }
    

    return 0;
}


