#include <iostream>
#include <string>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    int cnt = 10;

    for ( auto c : s ) {
        cnt -= 1;
        cout << c;

        if ( cnt == 0 ) {
            cnt = 10;
            cout << "\n";
        }
    }
    
    return 0;
}