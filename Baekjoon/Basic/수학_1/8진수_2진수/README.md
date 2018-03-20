1212번 8진수 2진수
---------------

8진수를 2진수로 바꿔 출력하는 문제입니다.  
8진수 한 자리를 2진수 세 자리로 바꿔 출력할 수 있습니다.  
이 문제에서 주의해야 할 점은, 8진수의 가장 높은 자리수를 2진수로 바꿔 출력할 때 0을 생략하는 부분을 따로 구현해야 합니다.

~~~ cpp
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string eight[8] = { "000", "001", "010", "011",
                    "100", "101", "110", "111" };

int main()
{
    string s;
    cin >> s;
    
    bool start = true;
    
    if ( s.size() == 1 && s[0] - '0' == 0 ) {
        cout << "0";
    }
    
    for ( int i = 0; i < s.size(); ++i ) {
        int n = s[i] - '0';
        
        if ( start == true && n < 4 ) {
            if ( n == 0 ) {
                continue;
            } else if( n == 1 ) {
                cout << "1";
            } else if ( n == 2 ) {
                cout << "10";
            } else if ( n == 3 ) {
                cout << "11";
            }
            
            start = false;
        } else {
            cout << eight[n];
            start = false;
        }
    }
    
    return 0;
}
~~~