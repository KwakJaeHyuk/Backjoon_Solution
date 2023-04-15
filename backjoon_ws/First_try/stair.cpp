#define MAX_Stair 300

#include <iostream>

using namespace std;

int main(){
    int stair[MAX_Stair] = {0, };
    int num_stair;
    int min = 0;
    int result;

    cin >> num_stair;

    for(int i = 1; i <= num_stair; i++){
        cin >> stair[i];                    // 시작점에서는 점수가 없음
    }

    for(int i = 0; i <= num_stair; i++){
        min = stair[i];
        
        if(i < num_stair - 3){        
            if((stair[i + 1] + stair[i + 2]) > (stair[i + 2] + stair[i + 3])){
                i += 2;
                result += (stair[i + 1] + stair[i + 2]);
            }
            else{
                i +=3;
                result += (stair[i + 2] + stair[i + 3]);
            }
        }
        else{
            
            if(min >= stair[i]){
                min = stair[i];
            }
        }
    }

    cout << result - min << endl;


}