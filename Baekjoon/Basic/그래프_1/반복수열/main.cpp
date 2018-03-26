#include <iostream>

using namespace std;

constexpr int MAX = 1000000;

int check[MAX] = { 0 };

int pow(int x, int p)
{
    int res = 1;
    for ( int i = 0; i < p; ++i ) {
        res *= x;
    }
    return res;
}

int next(int a, int p)
{
    int res = 0;
    while ( a > 0 ) {
        res += pow(a % 10, p);
        a /= 10;
    }
    return res;
}

int length(int a, int p, int cnt) 
{
    if ( check[a] != 0 ) {
        return check[a] - 1;
    }
    check[a] = cnt;
    int b = next(a, p);
    return length(b, p, cnt + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a = 0, p = 0;
    cin >> a >> p;
    cout << length(a, p, 1) << '\n';
    return 0;
}