#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    auto it = 0;
    freopen("in.txt", "r", stdin);
    int n, count = 0;
    cin >> n;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        count++;
    }
    cout << count << endl;

    return 0;
}
