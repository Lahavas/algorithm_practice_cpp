2444번 별찍기 - 7
---------------

마름모 모양의 별을 찍는 문제입니다.  
입력값이 N일 때 2 * N - 1 크기의 이등변 사각형을 그리고, 높이 N을 기점으로 위아래로 대칭인 모양입니다.  
그러므로 N보다 작을 때 증가하고, N보다 클 때 감소하는 이등변 감각형 모양의 별을 찍어 문제를 해결할 수 있습니다.  

1. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    
    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        int x = (i <= n ? i : (n * 2) - i);
        
        for ( int j = 0; j < (n * 2) - 1; ++j ) {
            if ( j + x < n ) {
                cout << ' ';
            } else {
                for ( int k = 1; k <= (x * 2) - 1; ++k ) {
                    cout << '*';
                }
                cout << '\n';
                break;
            }   
        }
    }
    
    return 0;
}
~~~

2. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>

int main()
{
    int n = 0;
    scanf("%d", &n);

    for ( int i = 1; i <= (n * 2) - 1; ++i ) {
        int x = (i <= n ? i : (n * 2) - i);

        for ( int j = 0; j < (n * 2) - 1; ++j ) {
            if ( j + x < n ) {
                putchar(' ');
            } else {
                for ( int k = 1; k <= (x * 2) - 1; ++k ) {
                    putchar('*');
                }
                putchar('\n');
                break;
            }
        }
    }

    return 0;
}
~~~