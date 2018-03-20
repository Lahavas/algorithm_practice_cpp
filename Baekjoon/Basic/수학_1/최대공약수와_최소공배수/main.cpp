#include <iostream>

using namespace std;

int gcd(int a, int b) 
{
    if ( b == 0 ) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0;
    cin >> a >> b;
    
    int g = gcd(a, b);
    int l = (a * b) / g;
    
    cout << g << '\n';
    cout << l << '\n';
    
    return 0;
}