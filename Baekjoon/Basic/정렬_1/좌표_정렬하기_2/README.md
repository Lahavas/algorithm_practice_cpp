11651번 좌표 정렬하기 2
-------------------

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
    
    sort(a.begin(), a.end(), 
        [](const pair<int, int> &u, const pair<int, int> &v) {
           return u.second == v.second ? u.first < v.first : u.second < v.second; 
        });
    
    for ( auto &p : a ) {
        printf("%d %d\n", p.first, p.second);
    }
}
~~~