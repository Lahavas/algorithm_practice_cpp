#include <iostream>

using namespace std;

int main(void)
{
    int cnt;
    cin >> cnt;

    for (int i = 1; i <= cnt; i++) {
        int a, b;
        cin >> a >> b;
        cout << "Case #" << i << ": " << a + b << endl;
    }

    return 0;
}