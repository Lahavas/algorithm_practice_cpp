11052번 붕어빵 판매하기
------------------

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> arr(n + 1, 0);
    for ( int i = 1; i <= n; i++ ) {
        cin >> arr[i];
    }

    vector<int> des(n + 1, 0);
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= i; j++ ) {
            des[i] = max(des[i], des[i - j] + arr[j]);
        }
    }

    cout << des[n] << endl;

    return 0;
}
~~~