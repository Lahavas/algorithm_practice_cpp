#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string input;
    cin >> input;

    int cnt = 10;
    for (int i = 0; i < input.size(); i++) {
        cnt--;
        cout << input.at(i);
        
        while (cnt == 0) {
            cnt = 10;
            cout << endl;
        }
    }
    
    return 0;
}