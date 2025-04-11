#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX_N 20
#define BOMB_TYPE_NUM 3
//나는 그냥 숫자를 넣어 버리는 것에 비해 변수 디파인을 하면 깔끔하고 법용적인 코드 생성가능

using namespace std;

int n;
int bomb_type[MAX_N][MAX_N];
bool bombed[MAX_N][MAX_N];  //뭐 이게 visited비슷한거다 

int ans;

vector<pair<int, int> > bomb_pos;
//그리드를 쓰니 않고 그냥 좌표만을 받기 위해 이런 기법을 쓰는 것이다. 나쁘지 않다. 비슷한 문제를 풀 수 있으면 괜찮겠다는 생각.

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Bomb(int x, int y, int b_type) {
    // 폭탄 종류마다 터질 위치를 미리 정의합니다.
    pair<int, int> bomb_shapes[BOMB_TYPE_NUM + 1][5] = {
        {}, //인덱스를 1에서 시작하기 위함
        { {-2, 0}, {-1, 0}, {0, 0},  {1, 0}, {2, 0}},
        { {-1, 0},  {1, 0}, {0, 0}, {0, -1}, {0, 1}},
        {{-1, -1}, {-1, 1}, {0, 0}, {1, -1}, {1, 1}}
    };
    //같은 방식의 접근 but 나와 달리 로컬로 정의를 하였음. 
    
    // 격자 내 칸에 대해서만 영역을 표시합니다.
    for(int i = 0; i < 5; i++) { //{0,0}의 설적으로 5가지가 된다. <-폭탄 위치를 포함한다고 돼있기 때문
        int dx, dy;
        tie(dx, dy) = bomb_shapes[b_type][i];
        // <tuple> 헤더 필요. tie를 안쓰면 다음 필요. 
        // dx = bomb_shapes[b_type][i].first;
        // dy = bomb_shapes[b_type][i].second;
        
        int nx = x + dx, ny = y + dy;
        if(InRange(nx, ny))
            bombed[nx][ny] = true;
    }
}

int Calc() {
    // Step1. 폭탄이 터진 위치를 표시하는 배열을
    // 초기화합니다.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			bombed[i][j] = false;
	
    // Step2. 각 폭탄의 타입에 따라 
    // 초토화 되는 영역을 표시합니다.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
            if(bomb_type[i][j])
                Bomb(i, j, bomb_type[i][j]);
	
    // Step3. 초토화된 영역의 수를 구합니다.
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
            if(bombed[i][j])
                cnt++;
    
	return cnt;
}

void FindMaxArea(int cnt) { //이게 백트레킹 파트 이다. 
	if(cnt == (int) bomb_pos.size()) {
		ans = max(ans, Calc()); //초토화가 최대 인파트를 계산한다. -> 이 때만 계산해주면 되는게 좋은 것 같다.
		return;
	}
	for(int i = 1; i <= 3; i++) {  //3개 포즈 돌아가면서 확인
        int x, y;
        tie(x, y) = bomb_pos[cnt];
        
		bomb_type[x][y] = i;  //이 장소에는 몇번이 터졌는가
		FindMaxArea(cnt + 1); //여기에 재귀 파트가 
		bomb_type[x][y] = 0;  //뒤로 되돌아가기 
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
            int bomb_place;
			cin >> bomb_place;
			if(bomb_place)
				bomb_pos.push_back(make_pair(i, j));
                // 이부분은 나랑 다르다. 그리드를 받는 게 아니라 그냥 좌표만 받도록 한다.
                // 벡터 사용의 좋은 예. 파이썬에서는 그냥 어팬드 원툴일 테다.
		}
	
	FindMaxArea(0);
	
	cout << ans;
	return 0;
}
