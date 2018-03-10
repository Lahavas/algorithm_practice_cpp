11650번 좌표 정렬하기
-----------------

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

    bool operator < (const Point &v) const {
        if ( x < v.x ) {
            return true;
        } else if ( x == v.x ) {
            return y < v.y;
        } else {
            return false;
        }
    }
};

int main() 
{
    int n;
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