#include <iostream>
#include <string>

// 내가 이해한대로의 문제였다면 맞는 풀이 방식이지만 문제 이해 실패로 틀린 풀이이다.

// 내가 이해한 문제 : 랜덤적으로 주어진 바둑판이 존재한다면 그 바둑판에서 격자형식으로 되어 있지 않은 부분을 수정함으로써, 옳바른 체스판으로 생성하는 것

using namespace std;

int main(int argc, char **argv)
{
    // length : 행의 개수, width : 열의 개수
    int width, length;
    cin >> length >> width;

    int err_cnt = 0;

    char color[width][length] = {0, };

    if((width < 8) || (length > 50))
    {
        cout << "error of range!" << endl;
    }
    
    // 값을 입력
    else
    {
        for(int i = 0; i < length; i++)
        {
            for(int j = 0; j < width; j++)
            {
                cin >> color[j][i];
            }
        }
    }

    // 첫 번째 행이 같은 경우 변경해줌
    for(int i = 0; i < width; i++)
    {
        if(color[i][0] == color[i+1][0])
        {
            if(color[i+1][0] == 'W')
            {
                color[i+1][0] = 'B';
            }
            else if(color[i+1][0] == 'B')
            {
                color[i+1][0] = 'W';
            }
        }
    }

    // 고쳐야하는 인덱스 부분을 세줌
    for(int i = 0; i < length-1; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(color[j][i] == color[j][i+1])
            {
                if(color[j][i+1] == 'W')
                {
                    color[j][i+1] = 'B';
                }
                else if(color[j][i+1] == 'B')
                {
                    color[j][i+1] = 'W';
                }
                err_cnt += 1;
            }
        }
    }

    printf("\n");

    //CHECK
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < width; j++)
        {
            printf("%c", color[j][i]);
        }
        printf("\n");
    }
    printf("고쳐야 하는 문자수 : %d", err_cnt);

    return 0;
}