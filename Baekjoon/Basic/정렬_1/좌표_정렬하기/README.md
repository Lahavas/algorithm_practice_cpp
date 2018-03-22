11650번 좌표 정렬하기
-----------------

좌표와 같이 두 자료형이 묶여있는 구조는 C++에서 제공하는 pair를 사용하면 편하게 풀이할 수 있습니다.  
이외의 방법으로는 struct를 직접 구현하여 풀이할 수 있습니다.  
Operator를 Overloading하는 방식과 sort 함수 내에 Lambda Expression을 구현하는 방식으로 문제를 해결하였습니다.  

1. pair Type을 사용하여 구현

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
    
    sort(a.begin(), a.end());
    for ( int i = 0; i < n; ++i ) {
        printf("%d %d\n", a[i].first, a[i].second);
    }
    
    return 0;
}
~~~

2. struct와 Operator Overloading을 통해 구현

~~~ cpp
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    Point() {
        x = 0;
        y = 0;
    }

    bool operator < (const Point &v) const {
        return (x == v.x ? y < v.y : x < v.x);
    }
};

int main() 
{
    int n = 0;
    scanf("%d", &n);

    vector<Point> a(n);

    for ( int i = 0; i < n; ++i ) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }

    sort(a.begin(), a.end());

    for ( int i = 0; i < a.size(); ++i ) {
        printf("%d %d\n", a[i].x, a[i].y);
    }

    return 0;
}
~~~

3. struct와 비교 함수를 통해 구현

~~~ cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    Point() {
        x = 0;
        y = 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector<Point> a(n);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].x >> a[i].y;
    }

    sort(a.begin(), a.end(), [](const Point &u, const Point &v) {
        return (u.x == v.x ? u.y < v.y : u.x < v.x);
    });

    for ( int i = 0; i < n; ++i ) {
        cout << a[i].x << ' ' << a[i].y << '\n';
    }

    return 0;
}
~~~