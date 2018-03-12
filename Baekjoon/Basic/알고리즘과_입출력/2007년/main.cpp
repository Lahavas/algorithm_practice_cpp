#include <iostream>
#include <string>

using namespace std;

const int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const string d[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main()
{
    ios_base::sync_with_stdio(false);

    int x = 0, y = 0;
    cin >> x >> y;

    int n = 0;
    for ( int i = 1; i < x; ++i ) {
        n += a[i - 1];
    }
    n += y;

    cout << d[n % 7] << '\n';

    return 0;
}