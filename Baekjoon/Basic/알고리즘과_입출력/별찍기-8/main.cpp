#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        int x = (i <= n ? i : (n * 2) - i);

        for ( int j = 1; j <= (n * 2); ++j ) {
            int y = (j <= n ? j : (n * 2) - j + 1);

            if ( x >= y ) {
                cout << '*';
            } else {
                cout << ' ';
            }
        }

        cout << '\n';
    }

    return 0;
}