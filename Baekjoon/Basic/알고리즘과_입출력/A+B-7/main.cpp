#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    for ( int i = 1; i <= cnt; ++i ) {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << '\n';
    }

    return 0;
}