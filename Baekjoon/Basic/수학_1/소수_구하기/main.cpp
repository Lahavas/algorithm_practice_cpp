#include <iostream>

using namespace std;

constexpr int MAX = 1000000;

bool check[MAX + 1] = { false };

int main()
{
    ios_base::sync_with_stdio(false);

    check[0] = true;
    check[1] = true;
    
    for ( int i = 2; i * i <= MAX; ++i ) {
        if ( check[i] == false ) {
            for ( int j = i + i; j <= MAX; j += i ) {
                check[j] = true;
            }
        }
    }
    
    int m = 0, n = 0;
    cin >> m >> n;
    
    for ( int i = m; i <= n; ++i ) {
        if ( check[i] == false ) {
            cout << i << '\n';
        }
    }
    
    return 0;
}