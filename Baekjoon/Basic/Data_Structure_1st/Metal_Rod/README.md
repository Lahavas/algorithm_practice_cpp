10799번 쇠막대기
-------------

'('는 긴 쇠막대기를 하나 더 늘리고, ')'는 긴 쇠막대기를 하나 줄이고 쇠막대기의 갯수를 하나 늘립니다.  
예외적인 경우는 '(' 다음에 ')'이 오는 경우인데, 이 땐 긴 쇠막대기의 갯수만큼 전체 쇠막대기 갯수를 늘려야합니다.  
Stack을 이용할 경우에 입력하는 괄호의 배열이 ')'가 먼저 오는 경우, 즉 Stack이 비어있을 때 Pop이 오는 경우가 존재하지 않음으로 따로 예외 처리를 해 줄 필요는 없습니다.

1. cstdio 사용, stack 사용 안함

~~~ cpp
#include <cstdio>

#define MAX 100000

int countRod(char* s) {
    int rod = 0;
    int result = 0;

    for ( int i = 0; i < MAX; i++ ) {
        if ( s[i] == '(' ) {
            if ( s[i + 1] == ')' ) {
                result += rod;
                i++;
            } else {
                rod++;
            }
        } else if ( s[i] == ')' ) {
            result++;
            rod--;
        } else {
            break;
        }
    } 

    return result;
}

int main() {
    char s[MAX];
    scanf("%s", s);

    printf("%d\n", countRod(s));

    return 0;
}
~~

2. iostream, stack 사용

~~~ cpp
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int countRod(string s) {
    stack<int> st;
    int result = 0;

    int size = s.size();

    for ( int i = 0; i < size; i++ ) {
        if ( s[i] == '(' ) {
            st.push(i);
        } else {
            if ( st.top() + 1 == i ) {
                st.pop();
                result += st.size();
            } else {
                st.pop();
                result += 1;
            }
        }
    } 

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    cout << countRod(s) << endl;;

    return 0;
}
~~