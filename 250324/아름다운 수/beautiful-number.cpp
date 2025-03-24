#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> seq;


int ans = 0;

//값으로 전달 -> 원본의 변형이 일어나지 않음
bool isBeuty (vector<int> seq){
    int cnt[5] = {0,0,0,0,0};
    for(int i=0;i<n;i++){
        int k = seq[i];
        cnt[k]++;
        if(i == n-1 || seq[i+1]!=seq[i]){
            if(cnt[k]!=k){
                return false;
            }
            else{
                cnt[k] = 0;
            }
        }
        else{
            if(cnt[k]==k){
                cnt[k] = 0;
            }
        }
    }
    return true;
}


void backtrack(){

    if (seq.size()==n){
        //수열이 완성되면 아름다운 수인지 확인
        if(isBeuty(seq)){
            ans++;
            // for(int i=0;i<seq.size();i++){
            //     cout << seq[i];
            // }
            // cout << ' ';
            
        }

        return;
    }

    for(int num=1;num<=4;num++){
        seq.push_back(num);
        backtrack();
        seq.pop_back();
    }
}


int main() {
    cin >> n;

    // Please write your code here.
    backtrack();

    //cout << endl;

    cout << ans << endl;

    return 0;
}
