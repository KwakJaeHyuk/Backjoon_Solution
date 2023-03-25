#define MAX 1001 // 배열의 크기를 우리가 예상하고 있는 값보다 1 크게 잡아야한다.
                 // 왜냐하면 배열은 0부터 값을 시작하지만 우리는 1부터 사용하기 때문이다.
#include <iostream>
#include <queue>

using namespace std;

int N, M, S; // 접점의 개수, 간선의 개수, 시작 위치
int line[MAX][MAX] = {0, };
int visited[MAX] = {0, }; 
queue<int> q;


void reset()
{
    for(int i = 1; i <= N; i++)
    {
        visited[i] = 0;    
    }
}

void DFS(int S)
{
    visited[S] = 1;
    cout << S << " ";

    for(int i = 1; i <= N; i++)
    {
        if(visited[i] == 0 && line[S][i] == 1) // 아직 방문하지 않은 노드이고, 간선이 연결되어 있는 경우에 그 노드에 대해서 다시 DFS 함수를 실행
        {
            DFS(i); // recurrent 방식을 차용
        }
    }
}

void BFS(int S)
{
    q.push(S);
    visited[S] = 1;
    cout << S << " ";

    while(!q.empty())
    {
        S = q.front();
        q.pop();

        for(int i = 1; i <= N; i++)
        {
            if(visited[i] == 0 && line[S][i] == 1)
            {
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
    for(int i = 0; i < M; i++)
    {
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
    cout << "\n";
}