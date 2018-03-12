10818번 최소, 최대
---------------

주어진 N개의 정수의 최소, 최대를 구하는 문제입니다.  
입력 가능한 정수의 최솟값, 최댓값을 미리 지정해놓고 이와 다른 정수들을 비교해가며 입력값의 최소, 최대를 구할 수 있습니다.
각 정수를 배열 또는 vector에 저장하는 방법도 있지만, 정수가 입력될 때마다 이전 결과와 비교하는 것이 더 효율적입니다.

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

constexpr int MIN_NUM = -1000000;
constexpr int MAX_NUM = 1000000;

int main()
{
    ios_base::sync_with_stdio(false);
            
    int cnt = 0;
    cin >> cnt;

    int min = MAX_NUM;
    int max = MIN_NUM;

    while ( cnt-- ) {
        int n = 0;
        cin >> n;

        if ( min > n ) {
            min = n;
        }

        if ( max < n ) {
            max = n;
        }
    }

    cout << min << " " << max << "\n";

    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

constexpr int MIN_NUM = -1000000;
constexpr int MAX_NUM = 1000000;

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);

    int min = MAX_NUM;
    int max = MIN_NUM;

    while ( cnt-- ) {
        int n = 0;
        scanf("%d", &n);

        if ( min > n ) {
            min = n;
        }

        if ( max < n ) {
            max = n;
        }
    }

    printf("%d %d\n", min, max);

    return 0;
}
~~~