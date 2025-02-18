#include <iostream>

using namespace std;

int n,m,k;
long long dp[105][105];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=0;i<=100;i++){
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            if(dp[i][j]==0){          
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    if (dp[n][m]<k){
        cout << -1 << endl;
        return 0;
    }


    while(n>0 || m>0){
        

        if(n>0 && dp[n-1][m]>=k){
            
            cout << 'a' ;
            n--;

        }
        else{
            cout << 'z';
            if(n>0) k -= dp[n-1][m];
            m--;
            
        }
    }
    cout << endl;
    return 0;
}

