2011번 암호코드
------------

D[N]은 N번째 문자까지 해석했을 때, 나올 수 있는 가짓수라고 정의할 수 있습니다.  
알파벳이 나올 수 있는 숫자의 범위는 1 ~ 26이므로, 한 자리 수를 차지하고 있는 경우와 두 자리 수를 차지하고 있는 경우를 분류하여 문제를 풀이할 수 있습니다.  
N번째 자리가 1부터 9일 경우, D[N] = D[N-1]이며,  
N번째 자리와 N-1번째 자리의 조합이 10부터 26일 경우, D[N] = D[N-1] + D[N-2] 입니다.

~~~ cpp
#include <iostream>
#include <vector>

using namespace std;

constexpr long mod = 1000000;

int main()
{
    ios_base::sync_with_stdio(false);

    string s = "";
    cin >> s;
    
    int n = s.size();
    s = " " + s;
    
    vector<long> d(n + 1, 0);
    
    d[0] = 1;
    
    for ( int i = 1; i <= n; ++i ) {
        int x = s[i] - '0';
        if ( x >= 1 && x <= 9 ) {
            d[i] += d[i - 1];
        }
        if ( i == 1 ) {
            continue;
        }

        x = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if ( x >= 10 && x <= 26 ) {
            d[i] += d[i - 2];
        }
        
        d[i] %= mod;        
    }
    
    cout << d[n] << '\n';
    
    return 0;
}
~~~