#define MAX_Stair 300

#include <iostream>

using namespace std;

int stair[MAX_Stair] = {0, };
int DP[MAX_Stair] = {0, };

int main(){
    
    int num_stair;

    cin >> num_stair;

    for(int i = 1; i <= num_stair; i++){
        cin >> stair[i];                    // 시작점에서는 점수가 없음
    }

    DP[1] = stair[1];
    DP[2] = stair[1] + stair[2];
    DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    for(int i = 4; i <= num_stair; i++){
        DP[i] = max(DP[i-2] + stair[i], DP[i -3] + stair[i - 1] + stair[i]);
    }
    cout << DP[num_stair] << endl;


}