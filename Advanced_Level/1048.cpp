#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int hasNum[100010] = {0};  //声明在主函数外避免段错误
int main() {
    freopen("in.txt", "r", stdin);
    int n, m, tmp;
    vector<int> v;
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v[i] = tmp;
        hasNum[tmp] += 1;
    }
    sort(v.begin(), v.end());
    for (int i : v) {
        if ((i != m - i && hasNum[m - i]) || (i == m - i && hasNum[i] > 1)) {
            cout << i << " " << m - i;
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}