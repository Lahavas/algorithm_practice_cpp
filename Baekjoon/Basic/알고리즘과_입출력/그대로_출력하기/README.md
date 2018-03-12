11718번 그대로 출력하기
------------------

string으로 입력받을 시에 그대로 출력하지 않고 단어 단위로 출력을 하기 때문에 character별로 입력받아야합니다.  
혹은 string header의 getline 함수를 통해 한 줄을 통채로 입력 받을 수 있습니다.  
fgets의 경우 '\n'까지 입력받기 때문에 출력시에 '\n'를 따로 입력받을 필요가 없습니다.    

1. cstdio header의 fgets Function을 사용하여 입력

~~~ cpp
#include <cstdio>

constexpr int MAX = 100;

int main() 
{
    char s[MAX] = { NULL };
    
    while ( fgets(s, sizeof(s), stdin) != NULL ) {
        printf("%s", s);
    }

    return 0;
}
~~~

2. cstdio header의 scanf Function을 사용하여 입력

~~~ cpp
#include <cstdio>

constexpr int MAX = 100;

int main() 
{
    char s[MAX] = { NULL };

    while ( scanf("%[^\n]\n", s) == 1 ) {
        printf("%s\n", s);
    }

    return 0;
}
~~~

3. string header의 getline Function을 사용하여 입력

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;

    while ( getline(cin, s) ) {
        cout << s << '\n';
    }

    return 0;
}
~~~