#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[16];

int main() {
    cin >> n;
    vector<pair<int, int>> jobs(n);
    
    for(int i = 0; i < n; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }
    
    // Bottom-up dynamic programming
    for(int i = n-1; i >= 0; i--) {
        int next_day = i + jobs[i].first;
        
        // Can complete this job
        if(next_day <= n) {
            dp[i] = max(jobs[i].second + (next_day < n ? dp[next_day] : 0), 
                        (i+1 < n ? dp[i+1] : 0));
        }
        // Cannot complete this job
        else {
            dp[i] = (i+1 < n ? dp[i+1] : 0);
        }
    }
    
    cout << dp[0] << '\n';

    return 0;
}