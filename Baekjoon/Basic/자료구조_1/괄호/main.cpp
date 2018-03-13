#include <iostream>
#include <string>

using namespace std;

bool isValid(string ps) 
{
    int n = 0;

    for ( auto a : ps ) {
        if ( a == '(' ) {
            n += 1;
        } else if ( a == ')' ) {
            n -= 1;
        } else {
            break;
        }

        if ( n < 0 ) {
            return false;
        }
    }

    return (n == 0 ? true : false);
}

int main() 
{
    ios_base::sync_with_stdio(false);

    int cnt = 0;
    cin >> cnt;

    string ps;

    while ( cnt-- ) {
        cin >> ps;

        if ( isValid(ps) == true ) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}