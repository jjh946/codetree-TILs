#include <iostream>
#include <algorithm>
//sort를 쓰기 위해 알고리즘을 써 줬다.

using namespace std;

//int n, total_sug, sug_id, photo[20], cnt[20], Time[20];
	//전역 변수(cnt_id)는 0으로 초기화 되어 있다는 것을 고려
	//했었지만, 출력을 할 때 쓰레기 값이 같이 나오는 문제가 생김
int n, total_sug, sug_id;
int photo[20] = {0};
int cnt[20] = {0};
int Time[20] = {0};
	
int WhoIsSmallest(int n, int *cnt, int *time){
	int smallest_index=0;
	
	for(int i=1;i<n;i++){
		if (cnt[i]<cnt[smallest_index]){
			smallest_index = i;
		}
		else if (cnt[i]==cnt[smallest_index]){
			if (time[i]<time[smallest_index]){
				smallest_index = i;
			}
		}
	}
	
	
	return smallest_index;
}



int main() {
	cin >> n; 
	cin >> total_sug;
	
	

	for(int i=0;i<total_sug;i++){
		cin >> sug_id;
		
		bool isDup = false;
		bool isEmpty = false;
		
		for(int j=0;j<n;j++){
			if (photo[j]==sug_id){ //이미 게시된 id면 추천횟수만 증가 
				cnt[j]++;
				isDup = true;
				break;
			}
		}
		
		if (!isDup){
			for(int j=0;j<n;j++){
				if (photo[j]==0){ //비어있는 사진 틀이 있을 때         
					//추천인 정보 기록 
					photo[j] = sug_id;
					cnt[j]++;
					Time[j]=i;
					isEmpty = true;
					break;
				}
			}
		}

		if(!isEmpty && !isDup){ //비어있는 사진 틀이 없고 중복이 되ㄴ지 않는 경우 
			int index = WhoIsSmallest(n,cnt,Time);
			photo[index] = sug_id;
			cnt[index] = 1;
			Time[index] = i;
		}
	}
	
	sort(photo,photo+n);
	
	for(int i=0;i<n;i++){
		if(photo[i]>0 && photo[i]<101){
			cout << photo[i] << ' ';
		}
	}
	cout << endl; //쓰레기 값이 뜨는게 혹시 모르니 개행 추가
	//개행 없어도 고쳐지긴 했다.
	


	return 0;
}