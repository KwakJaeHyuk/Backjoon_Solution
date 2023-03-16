#include <iostream>
#include <algorithm>

using namespace std;

int compare(string a, string b)
{
    // a, b는 아스키 코드로 나타내서 a < b로 정렬하게 된다면 사전순으로 정렬되게 된다.
    if(a.length() == b.length())
    {
        return a < b;
    }
    // 그러나 else문에서와 같이 길이가 다르다면 길이 순으로 정렬한다.
    else
    {
        return a.length() < b.length();
    }
}

// 문장의 개수 범위를 설정
string word[20000];

int main()
{
    int N;

    // 단어의 개수를 설정
    cin >> N;
   
    // 사용할 단어들을 입력
    for(int i = 0; i < N; i++)
    {
        cin >> word[i];
    }

    // sort 함수 : 첫번째랑 두번째 인자에서는 배열 범위를 설정해준다.
    //            세번째 인자에서 넣어주는 함수 compare 함수를 사용하여 compare 함수에 맞게 정렬이 동작하게 된다.
    sort(word, word + N, compare);

    for(int i = 0; i < N; i++)
    {
        // 만약 같은 단어가 있다면 무시하고 진행.
        if(word[i] == word[i - 1])
        {
            continue;
        }
        cout << word[i] << endl;
    }
    return 0;
}