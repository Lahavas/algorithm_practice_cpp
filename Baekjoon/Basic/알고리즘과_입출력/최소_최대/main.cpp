#include <iostream>

using namespace std;

constexpr int MIN_NUM = -1000000;
constexpr int MAX_NUM = 1000000;

int main()
{
    ios_base::sync_with_stdio(false);
            
    int cnt = 0;
    cin >> cnt;

    int min = MAX_NUM;
    int max = MIN_NUM;

    while ( cnt-- ) {
        int n = 0;
        cin >> n;

        if ( min > n ) {
            min = n;
        }

        if ( max < n ) {
            max = n;
        }
    }

    cout << min << " " << max << "\n";

    return 0;
}