#define MAX_N 100001
#define MAX_T 21
#include <iostream>

// 이 코드의 문제점 => 시간 초과 오류를 잡기 위해 for문을 없애고 재귀함수를 사용하였는데
//					  결국 재귀 함수를 사용하게 된다면 시간 복잡도 자체는 변하지 않기 때문에 별다른 변화는 없다.

using namespace std;

int func(int N, pair<int, int> num1[], int ans, int i) {

	i++;
	for (int k = 0; k < N; k++) {
		
		int maxFirst = num1[i].first;
		int maxSecond = num1[i].second;

		if (maxFirst > num1[k].first && maxSecond > num1[k].second) {
			ans++;
			break;
		}
	}

	if(i < N-1) 
		ans = func(N, num1, ans, i);

	return ans;
}


int main() {

	int T;
	int N;
	cin >> T;

	int ans[MAX_T] = { 0, };

	pair<int, int> num[MAX_N];

	for (int j = 0; j < T; j++) {
		cin >> N;


		for (int i = 0; i < N; i++) {
			int a, b;
			cin >> a >> b;

			num[i] = make_pair(a, b);
		}

		
		ans[j] = func(N, num, ans[j], -1);

		ans[j] = N - ans[j];

		
	}
	for (int i = 0; i < T; i++) {
		cout << ans[i] << endl;
	}
	
}