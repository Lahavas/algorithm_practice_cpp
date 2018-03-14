10808번 알파벳 개수
----------------

strlen으로 문제를 풀 경우, strlen 함수의 시간 복잡도는 O(N) 이기 때문에, **반복문 내에서 strlen 함수 사용은 추천하지 않습니다**.  
algorithm header의 count 함수를 사용하여 더욱 편리하게 해당 문제를 풀이할 수 있습니다.  

1. cstdio 사용

~~~ cpp
#include <cstdio>
#include <cstring>

constexpr int MAX = 101;

int main() 
{
    char s[MAX] = { '\0' };
    scanf("%s", s);

    for ( int i = 'a'; i <= 'z'; ++i) {
        int cnt = 0;

        int len = strlen(s);

        for ( int j = 0; j < len; ++j ) {
            if ( i == s[j] ) {
                cnt++;
            }
        }

        printf("%d ", cnt);
    }

    putchar('\n');

    return 0;
}
~~~

2. algorithm header의 count Function 사용

~~~ cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    for ( int i = 'a'; i <= 'z'; ++i ) {
        cout << count(s.begin(), s.end(), i) << ' ';
    }

    cout << '\n';

    return 0;
}
~~~