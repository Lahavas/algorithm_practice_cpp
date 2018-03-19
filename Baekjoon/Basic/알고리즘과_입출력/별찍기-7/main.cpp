#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        int x = (i <= n ? i : (n * 2) - i);

        for ( int s = 1; s <= n - x; ++s ) {
            cout << ' ';
        }
        for ( int t = 1; t <= (x * 2) - 1; ++t ) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}