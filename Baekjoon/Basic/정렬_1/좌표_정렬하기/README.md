11650번 좌표 정렬하기
-----------------

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