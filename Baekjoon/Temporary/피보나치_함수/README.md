1003번 피보나치 함수
----------------

~~~ cpp
#include <cstdio>

int zero = 0;
int one = 0;

int fibonacci(int n) 
{
    if (n == 0) {
        ++zero;
        return 0;
    } else if (n == 1) {
        ++one;
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);
    
    while ( cnt-- ) {
        int n = 0;
        scanf("%d", &n);
        
        fibonacci(n);
        printf("%d %d\n", zero, one);
        zero = 0;
        one = 0;
    }
    
    return 0;
}


~~~