#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n = "";
    int b = 0;
    
    cin >> n >> b;
    
    long res = 0;
    
    for ( int i = 0; i < n.size(); ++i ) {
        if ( n[i] >= '0' && n[i] <= '9' ) {
            res = res * b + (n[i] - '0');
        } else {
            res = res * b + (n[i] - 'A' + 10);
        }
    }
    
    cout << res << endl;
    
    return 0;
}