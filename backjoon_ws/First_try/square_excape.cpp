// 백준 1085번

#include <iostream>

using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int x_axis = w - x;
    int y_axis = h - y;

    int result = 0;
    if ((x > (w / 2)) || (y > (h / 2))) {
        if(x_axis < y_axis) {
            result = x_axis;
        }
        else {
            result = y_axis;
        }
    }
    else {
        if(x < y){
            result = x;
        }
        else{
            result = y;
        }
    }
    
    cout << result << endl;
}