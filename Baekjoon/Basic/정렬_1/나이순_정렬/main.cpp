#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct Person {
    int age;
    string name;

    Person() {
        age = 0;
    }

    bool operator < (const Person &v) const {
        return (age < v.age);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    vector<Person> a(n);

    for ( int i = 0; i < n; ++i ) {
        cin >> a[i].age >> a[i].name;
    }

    stable_sort(a.begin(), a.end());

    for ( auto &p : a ) {
        cout << p.age << ' ' << p.name << '\n';
    }

    return 0;
}