#include <iostream>
#include <queue> //priority_queue를 사용하기 위함
#include <functional> 

using namespace std;

int n;
int arr[100001];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0;i<n;i++) cin >> arr[i];

    priority_queue<int, vector<int> > pq;
    for (int i=0;i<n;i++) {
        int x = arr[i];
        if(x==0){
            if (pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
            
        }
        else{
            pq.push(x);
        }

    }


    return 0;
}