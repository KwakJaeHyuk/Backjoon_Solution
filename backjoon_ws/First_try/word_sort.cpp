// 백준 1181번

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string arr[100];
    string arr_ans[100];
    int num;
    
    string tmp1;
    string tmp2;

    cin >> num;

    for(int i = 0; i < num; i++)
    {
        cin >> arr[i];
    } 

    for(int i = 0; i < num; i++)
    {    
        for(int j = 0; j < num; j++)
        {
            if((arr[i].length() < arr[j].length()) && (arr[i].length() > arr[j-1].length()))
            {
                tmp1 = arr[i];
                tmp2 = arr[j-1];
                arr[j-1] = tmp1;
                arr[i] = tmp2;
            }
        }
    }

    // 이 코드의 문제점 : 같은 단어가 존재할 때 해결하지 못한다. 이 방식으로는 문제 해결이 안될 듯.
    // 같이 단어가 존재할 때 그 단어는 삭제함
     for(int i = 0; i < num; i++)
    {
        for(int j = 0 ; j < num; j++)
        {
            if(arr[i] == arr[j])
            {
                for(int k = j; k < num; k++)
                {
                    arr[k] = arr[k+1];
                }
            }
        }
    }
    
    for(int i = 0; i < num; i++)
    {
        cout << arr[i] << endl;
    }
}