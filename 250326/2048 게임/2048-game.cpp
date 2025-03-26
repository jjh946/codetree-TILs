#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int grid[20][20];
int max_value = 0;

// src를 dest로 복사
void copyGrid(int src[20][20], int dest[20][20]) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dest[i][j] = src[i][j];
        }
    }
}

// 한 줄을 "왼쪽"으로 밀 때의 병합 처리
vector<int> moveLine(const vector<int> &line) {
    // 1) 0 제거하여 압축
    vector<int> filtered;
    for(int v : line) {
        if(v != 0) filtered.push_back(v);
    }
    
    // 2) 인접한 같은 수 병합
    vector<int> merged;
    for(int i = 0; i < (int)filtered.size(); i++) {
        // 인접 두 수가 같으면 병합하고 건너뛴다
        if(i < (int)filtered.size() - 1 && filtered[i] == filtered[i + 1]) {
            merged.push_back(filtered[i] * 2);
            i++;
        } else {
            merged.push_back(filtered[i]);
        }
    }
    
    // 3) 남은 공간 0으로 채우기
    while((int)merged.size() < n) {
        merged.push_back(0);
    }
    
    return merged;
}

// dir 방향으로 기울이기
// 0: 위, 1: 아래, 2: 왼쪽, 3: 오른쪽
void moveBoard(int dir) {
    if(dir == 0) {
        // 위
        for(int j = 0; j < n; j++){
            // 열을 추출(위->아래)
            vector<int> col(n);
            for(int i = 0; i < n; i++){
                col[i] = grid[i][j];
            }
            // 왼쪽으로 병합하듯 처리
            col = moveLine(col);
            // 결과를 다시 그리드에 반영
            for(int i = 0; i < n; i++){
                grid[i][j] = col[i];
            }
        }
    } 
    else if(dir == 1) {
        // 아래
        for(int j = 0; j < n; j++){
            // 열을 추출(아래->위)
            vector<int> col(n);
            for(int i = 0; i < n; i++){
                col[i] = grid[n - 1 - i][j];
            }
            // 왼쪽 병합
            col = moveLine(col);
            // 다시 뒤집어서 그리드에 반영
            for(int i = 0; i < n; i++){
                grid[n - 1 - i][j] = col[i];
            }
        }
    } 
    else if(dir == 2) {
        // 왼쪽
        for(int i = 0; i < n; i++){
            // 행을 추출(왼->오)
            vector<int> row(n);
            for(int j = 0; j < n; j++){
                row[j] = grid[i][j];
            }
            // 왼쪽 병합
            row = moveLine(row);
            // 결과를 다시 그리드에 반영
            for(int j = 0; j < n; j++){
                grid[i][j] = row[j];
            }
        }
    } 
    else {
        // 오른쪽
        for(int i = 0; i < n; i++){
            // 행을 추출(오->왼)
            vector<int> row(n);
            for(int j = 0; j < n; j++){
                row[j] = grid[i][n - 1 - j];
            }
            // 왼쪽 병합
            row = moveLine(row);
            // 다시 뒤집어서 그리드에 반영
            for(int j = 0; j < n; j++){
                grid[i][n - 1 - j] = row[j];
            }
        }
    }
}

// 현재 보드에서 가장 큰 값
int getMax() {
    int ret = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ret = max(ret, grid[i][j]);
        }
    }
    return ret;
}

// 5번 이동하는 모든 경우의 수 탐색(백트래킹)
void dfs(int depth) {
    if(depth == 5) {
        max_value = max(max_value, getMax());
        return;
    }
    
    int backup[20][20];
    copyGrid(grid, backup);
    
    // 4방향 모두 시도
    for(int d = 0; d < 4; d++){
        moveBoard(d);
        dfs(depth + 1);
        // 원상복구
        copyGrid(backup, grid);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    
    dfs(0);
    cout << max_value << "\n";
    
    return 0;
}