9613번 GCD 합
------------

최대공약수를 구하는 가장 효과적인 방법은 유클리드 호제법(Euclidean Algorithm) 을 이용하는 방법입니다.  
A를 B로 나눈 나머지를 R이라고 했을 때, GCD(A, B) = GCD(B, R) 이 성립합니다.  
이 때, R이 0일 때 B는 최대공약수입니다.  

1. 재귀함수를 이용하여 최대공약수 구하기

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if ( b == 0 ) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;
    
    while ( cnt-- ) {
        int n = 0;
        cin >> n;
        
        vector<long> a(n, 0);
        for ( int i = 0; i < n; ++i ){
            cin >> a[i];
        }
        
        long sum = 0;
        for ( int i = 0; i < n - 1; ++i ) {
            for ( int j = i + 1; j < n; ++j ) {
                sum += gcd(a[i], a[j]);
            }
        }

        cout << sum << '\n';
    }
    
    return 0;
}
~~~

2. 재귀함수를 사용하지 않고 최대공약수 구하기

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while ( b != 0 ) {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    while ( cnt-- ) {
        int n = 0;
        cin >> n;

        vector<long> a(n, 0);
        for ( int i = 0; i < n; ++i ) {
            cin >> a[i];
        }

        long sum = 0;
        for ( int i = 0; i < n - 1; ++i ) {
            for ( int j = i + 1; j < n; ++j ) {
                sum += gcd(a[i], a[j]);
            }
        }

        cout << sum << '\n';
    }

    return 0;
}
~~~