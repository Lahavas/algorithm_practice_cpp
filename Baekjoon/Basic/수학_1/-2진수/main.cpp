#include <iostream>

using namespace std;

void convert(int n) 
{
    if ( n == 0 ) {
        return;
    }
    
    if ( n % 2 == 0 ) {
        convert(-(n / 2));
        cout << "0";
    } else {
        if ( n > 0 ) {
            convert(-(n / 2));
        } else {
            convert((-n + 1) / 2);
        }
        
        cout << "1";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    if ( n == 0 ) {
        cout << "0" << '\n';
    } else {
        convert(n);
        cout << '\n';
    }
    
    return 0;
}