2156번 포도주 시식
---------------

~~~ cpp
#include <cstdio>

#define MAX 10001

int a[MAX] = { 0 };
int d[MAX] = { 0 };

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    for ( int i = 1; i <= n; ++i ) {
        scanf("%d", &a[i]);
    }
    
    d[1] = a[1];
    d[2] = a[1] + a[2];
    
    for ( int i = 3; i <= n; ++i ) {
        d[i] = d[i - 1];
        
        if ( d[i] < d[i - 2] + a[i] ) {
            d[i] = d[i - 2] + a[i];
        }
        
        if ( d[i] < d[i - 3] + a[i - 1] + a[i] ) {
            d[i] = d[i - 3] + a[i - 1] + a[i];
        }
    }
    
    printf("%d\n", d[n]);
    
    return 0;
}
~~~