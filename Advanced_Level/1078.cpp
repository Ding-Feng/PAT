#include <iostream>
#include <vector>
using namespace std;
int MSize;
bool isPrime(int n) {
    if (n == 1 || n == 0) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
int insert(int key, vector<int> &v) {
    for (int step = 0; step < MSize; step++) {
        int index = (key + step * step) % MSize;
        if (v[index] == -1) {
            v[index] = key;
            return index;
        }
    }
    return -1;
}
bool flag = 1;
void print(int n) {
    if (n == -1)
        cout << " -";
    else {
        if (flag) {
            cout << n;
            flag = 0;
        } else {
            cout << " " << n;
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    int N, tmp;
    vector<int> v;
    cin >> MSize >> N;
    while (!isPrime(MSize)) MSize++;
    v.resize(MSize);
    fill(v.begin(), v.end(), -1);
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        print(insert(tmp, v));
    }
    return 0;
}