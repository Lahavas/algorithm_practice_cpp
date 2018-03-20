1373번 2진수 8진수
---------------

2진수를 8진수로 바꿔 출력하는 문제입니다.  
2진수의 세 자리 단위를 8진수 한 자리로 바꿔 출력할 수 있습니다.

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    
    int n = s.size();
    
    if ( n % 3 == 1 ) {
        cout << s[0];
    } else if ( n % 3 == 2 ) {
        cout << (s[0] - '0') * 2 + (s[1] - '0');
    }
    
    for ( int i = n % 3; i < n; i += 3 ) {
        cout << (s[i] - '0') * 4 + (s[i + 1] - '0') * 2 + (s[i + 2] - '0');
    }
    
    cout << '\n';
    
    return 0;
}
~~~