9012번 괄호
---------

VPS (Valid Parenthesis String) 을 찾는 문제입니다.  
VPS가 성립하기 위해서는 문자열 내의 '(' 와 ')' 가 전부 대응되어야 합니다.  
주의할 점은, ')' 다음에 '(' 가 오면 안된다는 점입니다. 즉 순서 또한 고려해서 풀어야합니다.  
Stack을 이용해서 풀 게 되면, '('일 경우 Push를, ')'일 경우 Pop을 해주고, Stack이 비어있을 때 Pop이 오면 No를 출력하도록 설계하면 됩니다.  

1. cstdio header를 사용하여 입출력

~~~ cpp
#include <cstdio>
#include <cstring>

constexpr int MAX = 50;

bool isValid(char *ps) 
{
    int n = 0;

    for ( int i = 0; i < strlen(ps); ++i ) {
        if ( ps[i] == '(' ) {
            n += 1;
        } else if ( ps[i] == ')' ) {
            n -= 1;
        } else {
            break;
        }

        if ( n < 0 ) {
            return false;
        }
    }

    return (n == 0 ? true : false);
}

int main() 
{
    int cnt = 0;
    scanf("%d", &cnt);

    char ps[MAX] = { '\0' };

    while ( cnt-- ) {
        scanf("%s", ps);

        if ( isValid(ps) == true ) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
~~~

2. iostream header를 사용하여 입출력

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

bool isValid(string ps) 
{
    int n = 0;

    for ( auto a : ps ) {
        if ( a == '(' ) {
            n += 1;
        } else if ( a == ')' ) {
            n -= 1;
        } else {
            break;
        }

        if ( n < 0 ) {
            return false;
        }
    }

    return (n == 0 ? true : false);
}

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    string ps;

    while ( cnt-- ) {
        cin >> ps;

        if ( isValid(ps) == true ) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
~~~