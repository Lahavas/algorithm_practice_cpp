#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= n - i; ++j ) {
            cout << ' ';
        }
        for ( int k = 1; k <= i * 2 - 1; ++k ) {
            if ( k % 2 == 0 ) {
                cout << ' ';
            } else {
                cout << '*';
            }
        }
        cout << '\n';
    }

    return 0;
}