10989번 수 정렬하기 3
-----------------

~~~ cpp
#include <cstdio>

constexpr int MAX = 10001;

int cnt[MAX] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    for ( int i = 0; i < n; ++i ) {
        int num = 0;
        scanf("%d", &num);
        ++cnt[num];
    }
    
    for ( int i = 1; i < MAX; ++i ) {
        if ( cnt[i] > 0 ) {
            for ( int j = 0; j < cnt[i]; ++j ) {
                printf("%d\n", i);
            }
        }
    }
    
    return 0;
}
~~~