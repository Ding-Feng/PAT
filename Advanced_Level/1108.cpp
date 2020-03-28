#include <bits/stdc++.h>
using namespace std;

bool check(string s) {
    double t;
    try {
        t = stod(s);
        if (t < -1000 || t > 1000) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                if (s.size() - i > 3) return false;
            }
        }
    } catch (const std::exception&) {
        return false;
    }
    return true;
}
int main() {
    freopen("in.txt", "r", stdin);
    int n, count = 0;
    double sum = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (!check(s)) {
            cout << "ERROR: " + s + " is not a legal number" << endl;
        } else {
            count++;
            sum += stod(s);
        }
    }
    if (count == 1)
        printf("The average of 1 number is %.2f", sum);
    else if (count > 1)
        printf("The average of %d numbers is %.2f", count, sum / count);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}