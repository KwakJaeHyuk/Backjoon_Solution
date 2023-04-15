#define MAX 101
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int maze[MAX][MAX] = {0, }; // maze map 생성 
int visited[MAX][MAX] = {0, }; // 방문 여부를 나타내기 위한 배열
int check[MAX][MAX] = {0, }; // 방문하는 경로의 합을 구하기 위해 사용

int dx[4] = {1, 0, -1,  0};
int dy[4] = {0, 1,  0, -1};

queue<pair<int, int>> q;

void createMaze(int row, int col){
    for(int i = 0; i < row; i++){
        string row1;
        cin >> row1;

        for(int j = 0; j < col; j++){
            maze[i][j] = row1[j] - '0'; // 문자열로 나타내었기 때문에 숫자로 나타내기 위해 '0'을 뺀다.
        }
    }
}

void BFS(int start_x, int start_y){
    visited[start_x][start_y] = 1;
    q.push(make_pair(start_x, start_y));
    check[start_x][start_y] += 1;

    while(!q.empty()){
        int x = q.front().first; // start_x
        int y = q.front().second; // start_y

        q.pop();
        for(int i = 0; i < 4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if((0 <= next_x && next_x < N) && (0 <= next_y && next_y < M)
            && !visited[next_x][next_y] && maze[next_x][next_y] == 1){

                visited[next_x][next_y] = 1;
                q.push(make_pair(next_x, next_y));
                check[next_x][next_y] = check[x][y] + 1;
            }
        }
    }
}

int main(){
    cin >> N >> M;

    createMaze(N, M);
    BFS(0, 0);
    cout << check[N - 1][M - 1];
}