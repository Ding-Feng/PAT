#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int maxN = 1000;
// O( \sqrt(n) ) 判断素数
bool IsPrime(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
bool isPrime[maxN];
int Prime[maxN], cnt = 0;
void GetPrime()  //筛到n
{
    isPrime[1] = false;
    for (int i = 2; i <= maxN; i++) {
        if (!isPrime[i]) Prime[++cnt] = i;

        for (int j = 1; j <= cnt && i * Prime[j] <= maxN; j++) {
            isPrime[i * Prime[j]] = 1;

            if (i % Prime[j] == 0) {
                break;
            }
        }
    }
}
int main() {
    GetPrime();
    for (int i = 1; i <= cnt; i++) {
        cout << Prime[i] << " ";
    }
    return 0;
}