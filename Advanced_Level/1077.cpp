#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string findPrefix(vector<string> &v) {
    for (int i = 0; i < v[0].size(); i++) {
        for (int j = 1; j < v.size(); j++) {
            if (v[j][i] != v[0][i]) {
                return v[0].substr(0, i);
            }
        }
    }
    return v[0];
}
int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    getchar();
    string res;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        reverse(s.begin(), s.end());
        v.push_back(s);
    }
    res = findPrefix(v);
    reverse(res.begin(), res.end());
    if (res.size() == 0) res = "nai";
    cout << res << endl;
    return 0;
}
