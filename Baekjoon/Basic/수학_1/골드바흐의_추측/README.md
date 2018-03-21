6588번 골드바흐의 추측
------------------

골드바흐의 추측은 *2보다 큰 모든 짝수는 두 소수의 합으로 표현 가능하다* 라는 이론입니다.  
즉, 해당 문제를 풀이하기 위해서는 **에라토스테네스의 채** 를 사용하여 N 이하의 소수를 구한 뒤,  
N - P[I]가 소수인지 판별하는 방법으로 문제를 해결할 수 있습니다.  

~~~ cpp
#include <cstdio>

constexpr int MAX = 1000000;

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
            for ( int j = i + i; j <= MAX; j += i ) {
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