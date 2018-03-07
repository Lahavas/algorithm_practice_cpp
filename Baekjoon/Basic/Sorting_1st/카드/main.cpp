#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    scanf("%d", &n);
    
    vector<long long> a(n, 0);
    for ( int i = 0; i < n; ++i ) {
        scanf("%lld", &a[i]);
    }
    
    sort(a, a + n);
    
    long long max = a[0];
    int max_cnt = 1;
    int cnt = 1;
    
    for ( int i = 1; i < n; ++i ) {
        if ( a[i] == a[i - 1] ) {
            ++cnt;
        } else {
            cnt = 1;
        }
        
        if ( max_cnt < cnt ) {
            max_cnt = cnt;
            max = a[i];
        }
    }
    
    printf("%lld\n", max);
    
    return 0;
}