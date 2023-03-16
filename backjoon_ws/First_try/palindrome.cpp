#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while(1)
    {
        int no = 0;
        cin >> s;
        // s의 자료형이 string일 경우 ""를 사용해야 한다.
        if(s == "0"){
            break;
        }

        
        // 홀수일 경우에도 '/'연산자를 사용하게 된다면 짝수일 때하고 동일한 부분까지만 범위가 지정될 수 있다.
        for(int i = 0; i < s.size()/2; i++)
        {   
            if(s[i] != s[s.size() - i - 1])
            {
                no += 1;
                break;
            }
        }
        

        if(no == 1)
        {
            cout << "no" << endl;
        }
        else if(no == 0)
        {
            cout << "yes" << endl;
        }
       
    }

}