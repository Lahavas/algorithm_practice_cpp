#include <iostream>

using namespace std;

void convert(int num, int base)
{
    if ( num == 0 ) {
        return;
    }
    
    convert(num / base, base);
    cout << num % base << " ";
}

int main()
{
    int a = 0, b = 0;
    cin >> a >> b;
    
    int m = 0;
    cin >> m;
    
    int res = 0;
    for ( int i = 0; i < m; ++i ) {
        int x;
        cin >> x;
        res = res * a + x;
    }
    convert(res, b);
    
    return 0;
}