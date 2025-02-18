#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int dp[4001][4001];

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    cin >> str1 >> str2;
    n = str1.size();
    m = str2.size();
    //cout << n << ',' << m << endl;

    int mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                //cout << i << ',' << j << endl;
            }// 이외에는 dp[i][j]==0;
            if(dp[i][j]>mx){
                mx = dp[i][j];
            }
        }
    }
    cout << mx << '\n';

    return 0;
}