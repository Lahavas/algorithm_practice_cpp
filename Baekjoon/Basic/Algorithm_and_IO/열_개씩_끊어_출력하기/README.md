11721번 열 개씩 끊어 출력하기
-----------------------

1. 10자씩 입력받아 출력

~~~ cpp
#include <cstdio>

#define MAX 110

int main() {
    char s[MAX];
    
    while ( scanf("%10s", s) == 1 ) {
        printf("%s\n", s);
    }

    return 0;
}
~~~

2. string으로 입력받아 끊어서 출력

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int cnt = 10;

    for ( int i = 0; i < s.size(); i++ ) {
        cnt--;
        cout << s.at(i);

        if ( cnt == 0 ) {
            cnt = 10;
            cout << endl;
        }
    }

    return 0;
}
~~~