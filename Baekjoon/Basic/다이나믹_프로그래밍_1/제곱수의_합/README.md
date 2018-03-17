1699번 제곱수의 합
---------------

D[N]은 N을 제곱수의 합으로 표현할 때, 항의 최소 갯수라고 정의할 수 있습니다.  
D[N] = min(N, min(D[N-1^2] + 1, D[N-2^2] + 1, ..., D[N-K^2] + 1)), (N >= K^2) 이라고 할 수 있습니다.

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<int> d(n + 1, 0);
    
    for ( int i = 1; i <= n; ++i ) {
        d[i] = i;
        for ( int j = 1; j * j <= i; ++j ) {
            if ( d[i] > d[i - (j * j)] + 1 ) {
                d[i] = d[i - (j * j)] + 1;
            }
        }
    }
    
    cout << d[n] << '\n';
    
    return 0;
}
~~~