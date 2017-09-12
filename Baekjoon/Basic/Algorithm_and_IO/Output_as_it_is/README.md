11718번 그대로 출력하기
------------------

string으로 입력받을 시에 그대로 출력하지 않고 단어 단위로 출력을 하기 때문에 character별로 입력받아야합니다.  
혹은 string의 getline 함수를 통해 한 줄을 통채로 입력 받을 수 있습니다.
fgets의 경우 '\n'까지 입력받기 때문에 출력시에 '\n'를 따로 입력받을 필요가 없다.  

1. fgets 사용

~~~ cpp
#include <cstdio>

#define MAX 101

int main() {
    char input[MAX];
    
    while ( fgets(input, sizeof(input), stdin) != NULL ) {
        printf("%s", input);
    }

    return 0;
}
~~~

2. scanf 사용

~~~ cpp
#include <cstdio>

#define MAX 101

int main() {
    char input[MAX];

    while ( scanf("%[^\n]\n", input) != EOF ) {
        printf("%s\n", input);
    }

    return 0;
}
~~~

3. getline 사용

~~~ cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string input;

    while ( getline(cin, input) ) {
        cout << input << endl;
    }

    return 0;
}
~~~