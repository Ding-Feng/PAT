#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

long long transform(string n, long long radix) {
    long long res = 0;
    int index = 0, tmp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        tmp = isdigit(*it) ? (*it - '0') : (*it - 'a' + 10);
        res += tmp * pow(radix, index++);
    }

    return res;
}
long long findRadix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0' : it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = transform(n, mid);
        if (t < 0 || t > num) {
            high = mid - 1;
        } else if (t == num) {
            return mid;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    //边界测试点
    // 12 c 1 10
    // 0 0 1 100
    // freopen("in.txt", "r", stdin);
    long long tag, radix;
    long long resultRadix;
    string n1, n2;
    cin >> n1 >> n2 >> tag >> radix;
    // cout << transform(n1, 10) << endl;
    // cout << transform(n2, 1) << endl;
    // return 0;
    resultRadix = tag == 1 ? findRadix(n2, transform(n1, radix))
                           : findRadix(n1, transform(n2, radix));
    if (resultRadix == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << resultRadix;
    }
    return 0;
}
