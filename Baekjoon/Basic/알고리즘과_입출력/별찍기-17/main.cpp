#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 1; i <= n; ++i ) {
        for ( int s = 1; s <= n - i; ++s ) {
            cout << ' ';
        }
        for ( int t = 1; t <= (i * 2) - 1; ++t ) {
            if ( t == 1 || t == (i * 2) - 1 ) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    
    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        cout << '*';
    }
    cout << '\n';

    return 0;
}