#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Person {
    string name;
    int kor, eng, math;

    Person() {
        kor = 0;
        eng = 0;
        math = 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    
    vector<Person> a(n);
    
    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].name >> a[i].kor >> a[i].eng >> a[i].math;
    }
    
    sort(a.begin(), a.end(), [](const Person &u, const Person &v) {
        if ( u.kor == v.kor ) {
            if ( u.eng == v.eng ) {
                if ( u.math == v.math ) {
                    return u.name < v.name;
                } else {
                    return u.math > v.math;
                }
            } else {
                return u.eng < v.eng;
            }
        } else {
            return u.kor > v.kor;
        }
    });
    
    for ( auto &p : a ) {
        cout << p.name << '\n';
    }
    
    return 0;
}