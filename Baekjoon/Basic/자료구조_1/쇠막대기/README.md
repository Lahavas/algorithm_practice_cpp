10799번 쇠막대기
-------------

'('는 긴 쇠막대기를 하나 더 늘리고, ')'는 긴 쇠막대기를 하나 줄이고 쇠막대기의 갯수를 하나 늘립니다.  
예외적인 경우는 '(' 다음에 ')'이 오는 경우인데, 이 땐 긴 쇠막대기의 갯수만큼 전체 쇠막대기 갯수를 늘려야합니다.  
Stack을 이용할 경우에 입력하는 괄호의 배열이 ')'가 먼저 오는 경우, 즉 Stack이 비어있을 때 Pop이 오는 경우가 존재하지 않음으로 따로 예외 처리를 해 줄 필요는 없습니다.

1. cstdio header를 사용하여 입출력, stack 사용 안함

~~~ cpp
#include <cstdio>
#include <cstring>

constexpr int MAX = 100000;

int countRod(char *a) 
{
    int rod = 0;
    int res = 0;

    for ( int i = 0; i < strlen(a); ++i ) {
        if ( a[i] == '(' ) {
            if ( a[i + 1] == ')' ) {
                res += rod;
                i += 1;
            } else {
                rod += 1;
            }
        } else if ( a[i] == ')' ) {
            res += 1;
            rod -= 1;
        } else {
            break;
        }
    } 

    return res;
}

int main() 
{
    char a[MAX] = { '\0' };
    scanf("%s", a);

    printf("%d\n", countRod(a));

    return 0;
}
~~

2. iostream header를 사용하여 입출력, stack 사용

~~~ cpp
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int countRod(string a) 
{
    stack<int> s;
    int res = 0;

    int size = a.size();

    for ( int i = 0; i < size; ++i ) {
        if ( a[i] == '(' ) {
            s.push(i);
        } else {
            if ( s.top() + 1 == i ) {
                s.pop();
                res += s.size();
            } else {
                s.pop();
                res += 1;
            }
        }
    } 

    return res;
}

int main() 
{
    ios_base::sync_with_stdio(false);

    string a;
    cin >> a;

    cout << countRod(a) << endl;;

    return 0;
}
~~