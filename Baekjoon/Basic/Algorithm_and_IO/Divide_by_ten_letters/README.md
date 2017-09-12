11721번 열 개씩 끊어 출력하기
-----------------------

1. 10자씩 입력받아 출력

~~~ cpp
#include <cstdio>

#define MAX 101

int main() {
    char input[MAX];
    
    while ( scanf("%10s", input) == true) {
        printf("%s\n", input);
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
    string input;
    cin >> input;

    int cnt = 10;

    for ( int i = 0; i < input.size(); i++) {
        cnt--;
        cout << input.at(i);

        if ( cnt == 0 ) {
            cnt = 10;
            cout << endl;
        }
    }

    return 0;
}
~~~