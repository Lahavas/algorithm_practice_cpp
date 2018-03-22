11651번 좌표 정렬하기 2
-------------------

좌표와 같이 두 자료형이 묶여있는 구조는 C++에서 제공하는 pair를 사용하면 편하게 풀이할 수 있습니다.  
해당 문제의 경우는 sort의 3번째 인자인 comp Function이 default Function인 Operator < 가 아니기 때문에,  
직접 comp Function 의 기능을 구현하여야 합니다.  
다른 방법으로는 x좌표와 y좌표를 바꿔 Default Function으로 정렬을 진행하는 방법으로 문제를 해결할 수 있습니다.  

1. comp Function 직접 구현

~~~ cpp
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    vector<pair<int, int>> a(n);
    for ( int i = 0; i < n; ++i ) {
        scanf("%d %d", &a[i].first, &a[i].second);
    }
    
    sort(a.begin(), a.end(), [](const pair<int, int> &u, const pair<int, int> &v) {
        return u.second == v.second ? u.first < v.first : u.second < v.second; 
        });
    
    for ( auto &p : a ) {
        printf("%d %d\n", p.first, p.second);
    }
}
~~~

2. x좌표와 y좌표를 반대로 입출력

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector<pair<int, int>> a(n);
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].second >> a[i].first;
    }

    sort(a.begin(), a.end());

    for ( auto &p : a ) {
        cout << p.second << ' ' << p.first << '\n';
    }

    return 0;
}
~~~