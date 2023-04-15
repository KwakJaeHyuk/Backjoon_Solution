#define MAX_N 100001
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin >> T;
    int cnt_array[21];
    pair<int, int> num[MAX_N];

    for(int j = 0; j < T; j++){
        int N;
        cin >> N;
        
        for(int i = 0; i < N; i++){
            int a, b;
            cin >> a >> b;
            num[i] = make_pair(a, b);
        }

        sort(num, num + N);

        int max_score = num[0].second; // 정렬된 상태의 second 열의 첫번째 값을 max_score에 저장
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if (num[i].second <= max_score){
                cnt++;
                max_score = num[i].second;
            }
        }

        cnt_array[j] = cnt;
    }

    for(int i = 0; i < T; i++){
        cout << cnt_array[i] << endl;
    }
}