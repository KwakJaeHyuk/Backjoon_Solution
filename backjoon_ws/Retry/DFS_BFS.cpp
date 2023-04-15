#define MAX 1001
#include <iostream>
#include <queue>

using namespace std;

int N, M, S;
int visited[MAX] = {0, };
int line[MAX][MAX] = {0, };
queue<int> q;

void reset(){
    for(int i = 1; i <= N; i++)
    {
        visited[i] = 0;
    }
}

void DFS(int S){
    cout << S << " ";
    visited[S] = 1;

    for(int i = 1; i <= N; i++){
        if(visited[i] == 0 && line[S][i] == 1){
            visited[i] = 1;
            DFS(i);
        }

    }
}

void BFS(int S){
    q.push(S);
    visited[S] = 1;
    cout << S << " ";

    while(!q.empty()){
        S = q.front();
        q.pop();

        for(int i = 1; i <= N; i++){
            if(visited[i] == 0 && line[S][i] == 1){
                q.push(i);
                visited[i] = 1;
                cout << i << " ";
            }
        }
    }
}

int main()
{
    cin >> N >> M >> S;
    for(int i = 0; i < M; i++){
        
        int line1 = 0;
        int line2 = 0;
        cin >> line1 >> line2;
        line[line1][line2] = 1; line[line2][line1] = 1;
    }

    reset();
    DFS(S);

    cout << "\n";

    reset();
    BFS(S);

    return 0;
}