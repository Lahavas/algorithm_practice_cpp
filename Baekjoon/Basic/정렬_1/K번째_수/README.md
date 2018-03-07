11004번 K번째 수
--------------

~~~ cpp
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    int k = 0;
    scanf("%d %d", &n, &k);
    --k;
    
    vector<long> a(n, 0);
    for ( int i = 0; i < n; ++i ) {
        scanf("%ld", &a[i]);
    }
    
    nth_element(a.begin(), a.begin() + k, a.end());
    printf("%ld\n", a[k]);
    
    return 0;
}
~~~