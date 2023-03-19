#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int start = 666;

    string num;
    int cnt = 0;

    while(1)
    {
        num = to_string(start); // temp의 길이를 측정하기 위해

        for(int i = 0; i < num.size() - 2; i++) // temp의 길이 만큼 for문을 돌림
                                                // num.size()에 -2를 한 이유는 666 연속된 세자리 수가 필요하기 때문이다.
        {
            if((num[i] == '6') && (num[i+1] == '6') && (num[i+2] == '6')) // 연속된 666이 있을 경우 cnt에 +1을 해주고 for문 탈출(연속된 6이 세개 이상인 경우도 있기 때문)
            {
                cnt++;
                break;
            }
        }

        if(cnt == n) // cnt 값이 n과 같아 졌을 때의 숫자를 출력하기 위한 for문
        {
            cout << start << endl;
            break;
        }

        start += 1;
    }

    return 0;
}