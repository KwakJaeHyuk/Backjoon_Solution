# include <iostream>
# include <algorithm>

using namespace std;

int main()
{
    int x, y, w, h;
    int tmp1, tmp2;
    int result;

    cin >> x >> y >> w >> h;

    tmp1 = min(x, y);
    tmp2 = min(w-x, h-y);

    result = min(tmp1, tmp2);
    cout << result << endl;
}