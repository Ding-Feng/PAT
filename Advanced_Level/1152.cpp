#include <iostream>
#include <string>
using namespace std;
bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int main(void) {
    freopen("in.txt", "r", stdin);
    int l, k, a;
    int flag;
    string s, temp;
    cin >> l >> k >> s;
    for (int i = 0; i <= l - k; i++) {
        temp = s.substr(i, k);
        a = stoi(temp);
        if (isPrime(a)) {
            cout << temp << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0) cout << "404" << endl;
    return 0;
}