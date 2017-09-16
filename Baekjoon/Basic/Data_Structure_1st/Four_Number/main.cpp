#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    string num_one = to_string(a) + to_string(b);
    string num_two = to_string(c) + to_string(d);

    long result = stol(num_one) + stol(num_two);

    cout << result << endl;

    return 0;
}