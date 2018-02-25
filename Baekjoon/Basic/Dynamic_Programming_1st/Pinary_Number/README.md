2193번 이친수
----------

1. 일반적인 방법으로 풀이

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<long> d(n + 1, 0); 

    for ( int i = 1; i <= n; i++ ) {
        if ( i == 1 ) {
            d[1] = 1;
        } else if ( i == 2 ) {
            d[2] = 1;
        } else {
            d[i] = d[i - 1] + d[i - 2];
        }
    }

    cout << d[n] << endl;

    return 0;
}
~~~

2. N번째 숫자에 따라 다르게 저장해서 풀이

~~~ cpp
#include <cstdio>

#define MAX 91

long d[MAX][2] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= n; i++ ) {
        if ( i == 1 ) {
            d[i][1] = 1;
            continue;
        } else if ( i == 2 ) {
            d[i][0] = 1;
            continue;
        }

        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }

    printf("%d\n", d[n][0] + d[n][1]);

    return 0;
}
~~~