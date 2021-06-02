//
// Created by Владислав on 02.06.2021.
//

#include <iostream>
#include <vector>

using namespace std;

template<class T>
void print(vector<T> a) {
    for (T i : a) {
        cout << i << ' ';
    }
    cout << '\n';
}

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(min(r - i, z[i - l]), 0);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i] += 1;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    z[0] = n;
    return z;
}

vector<int> a_funtion(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    s += t;
    auto z = z_function(s);
    vector<int> a;
    for (int i = s.size() / 2; i < s.size(); i++) {
        a.push_back(z[i]);
    }
    reverse(a.begin(), a.end());
    return a;
}

int main() {
    string s;
    cin >> s;
    print(a_funtion(s));
    print(z_function(s));
    return 0;
}
