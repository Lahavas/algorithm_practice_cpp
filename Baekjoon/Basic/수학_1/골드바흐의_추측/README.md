6588번 골드바흐의 추측
------------------

~~~ cpp
#include <cstdio>

const int MAX = 1000000;

int prime[MAX] = { 0 };
int pn = 0;

bool check[MAX + 1] = { false };

int main()
{
    check[0] = true;
    check[1] = true;
    for ( int i = 2; i * i <= MAX; ++i ) {
        if ( check[i] == false ) {
            prime[pn++] = i;
            for ( int j = i * i; j <= MAX; j += i ) {
                check[j] = true;
            }
        }
    }
    
    while ( true ) {
        int n = 0;
        scanf("%d", &n);
        
        if ( n == 0 ) {
            break;
        }
        
        for ( int i = 1; i <= pn; ++i ) {
            if ( check[n - prime[i]] == false ) {
                printf("%d = %d + %d\n", n, prime[i], n - prime[i]);
                break;
            }
        }
    }
    
    return 0;
}
~~~