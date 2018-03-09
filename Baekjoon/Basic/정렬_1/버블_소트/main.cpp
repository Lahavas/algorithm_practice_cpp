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
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    
    sort(a.begin(), a.end());
    
    int res = 0;
    for ( int i = 0; i < n; ++i ) {
        if ( res < a[i].second - i ) {
            res = a[i].second - i;
        }
    }
    
    printf("%d\n", res + 1);
    return 0;
}