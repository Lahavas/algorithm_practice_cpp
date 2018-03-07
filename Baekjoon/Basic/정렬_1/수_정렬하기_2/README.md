2751번 수 정렬하기 2
-----------------

~~~ cpp
#include <cstdio>
#include <algorithm>

constexpr int MAX = 1000000;

int a[MAX] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &a[i]);
    }
    
    std::sort(a, a + n);
    
    for ( int i = 0; i < n; ++i ) {
        printf("%d\n", a[i]);
    }
    
    return 0;
}
~~~