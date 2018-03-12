#include <iostream>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    while ( cnt-- ) {
        int a = 0, b = 0;
        cin >> a >> b;
        cout << a + b << '\n';
    }

    return 0;
}