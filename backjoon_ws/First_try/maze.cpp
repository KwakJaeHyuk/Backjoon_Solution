//#define MAX 101
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int N, M;
//int maze[MAX][MAX];
//int check[MAX][MAX];
//int visited[MAX][MAX];
//
//int dx[4] = {-1, 1, 0, 0};
//int dy[4] = {0, 0, -1, 1};
//
//queue<pair<int, int>> q;
//
//// void createMaze(int N, int M){
////     for(int i = 0; i < N; i++)
////     {
////         string row;                     
////         cin >> row;
//
////         for (int j=0; j < M; ++j){       
////             maze[i][j] = row[j]-'0';    
////         }
////     }
//// }
//
//void BFS(int x, int y)
//{
//    visited[x][y] = 1;
//    
//    q.push(make_pair(x, y));
//    check[x][y]++;
//
//    while(!q.empty()){
//        int x = q.front().first;
//        int y = q.front().second;
//
//        q.pop();
//        for(int i = 0; i < 4; ++i){
//            int next_x = x + dx[i];
//            int next_y = y + dy[i];
//
//            if ( (0 <= next_x && next_x < N) && (0 <= next_y && next_y < M) 
//            && !visited[next_x][next_y] && maze[next_x][next_y] == 1 ){
//                    
//                    visited[next_x][next_y] = 1;
//                    q.push(make_pair(next_x, next_y));
//                    check[next_x][next_y] = check[x][y] + 1;
//                
//            }
//        }
//    }
//}
//
//// count visited
//
//
//int main(){
//    cin >> N >> M;    
//    // createMaze(N, M);
//
//    for(int i = 0; i < N; ++i)
//    {
//        string row;                     
//        cin >> row;
//
//        for (int j=0; j < M; ++j){       
//            maze[i][j] = row[j]-'0';    
//        }
//    }
//
//    BFS(0, 0);
//    cout << check[N - 1][M - 1];
//}


#include <iostream>
#include <algorithm>

using namespace std;

int var[] = { 0, };

int main() {
    int num;
    int value;

    int ans = 0;

    cin >> num >> value;

    for (int i = 0; i < num; i++) {
        cin >> var[i];
    }

    for (int i = 0; i < num; i++) {
        while (value >= 0) {
            value -= var[i];
            ans += 1;
        }
    }
    cout << ans << endl;
}