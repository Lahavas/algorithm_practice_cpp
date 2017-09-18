10809번 알파벳 찾기
----------------

strlen으로 문제를 풀 경우, strlen 함수의 시간 복잡도는 O(N) 이기 때문에, 반복문 내에서 strlen 함수 사용은 추천하지 않습니다.  
algorithm header의 find 함수를 사용하여 더욱 편리하게 해당 문제를 풀이할 수 있습니다.  

1. cstdio 사용

~~~ cpp
#include <cstdio>
#include <cstring>

#define MAX 101

int main() {
    char s[MAX];
    scanf("%s", s);

    for ( int i = 'a' ; i <= 'z'; i++ ) {
        int index = -1;

        int len = strlen(s);

        for ( int j = 0; j < len; j++ ) {
            if ( i == s[j] ) {
                index = j;
                break;
            }
        }
        
        printf("%d ", index);
    }

    printf("\n");

    return 0;
}
~~

2. find 함수 사용

~~~ cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    for ( int i = 'a' ; i <= 'z'; i++ ) {
        auto it = find(s.begin(), s.end(), i);
    
        if ( it == s.end() ) {
            cout << -1 << ' ';
        } else {
            cout << (it - s.begin()) << ' ';
        }
    }

    cout << endl;

    return 0;
}
~~~