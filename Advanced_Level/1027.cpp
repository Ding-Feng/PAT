#include <bits/stdc++.h>
using namespace std;
string change(int n, vector<string> Mars) {
    string s = "";
    if (n / 13 == 0) {
        s += "0";
        s += Mars[n];
    } else {
        s += Mars[n / 13];
        s += Mars[n % 13];
    }
    return s;
}
int main() {
    freopen("in.txt", "r", stdin);
    vector<string> Mars = {"0", "1", "2", "3", "4", "5", "6",
                           "7", "8", "9", "A", "B", "C"};
    int a, b, c;
    cin >> a >> b >> c;
    cout << "#" << change(a, Mars) << change(b, Mars) << change(c, Mars)
         << endl;
    return 0;
}
