11052번 붕어빵 판매하기
------------------

D[N]은 붕어빵을 N개 팔아서 얻을수 있는 수익이라고 정의할 수 있습니다.  
D[N] = max(D[N-1] + P[1], D[N-2] + P[2], ..., D[N-K] + P[K], ... D[N]) 이라고 할 수 있습니다.

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> p(n + 1, 0);
    for ( int i = 1; i <= n; ++i ) {
        cin >> p[i];
    }

    vector<int> d(n + 1, 0);
    for ( int i = 1; i <= n; ++i ) {
        for ( int j = 1; j <= i; ++j ) {
            d[i] = max(d[i], d[i - j] + p[j]);
        }
    }

    cout << d[n] << '\n';

    return 0;
}
~~~