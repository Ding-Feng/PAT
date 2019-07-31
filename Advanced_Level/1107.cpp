#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> father, isRoot;
int find(int x) {
    if (x != father[x]) {
        father[x] = find(father[x]);
    }
    return father[x];
}
void Union(int x, int y) {
    int faX = find(x);
    int faY = find(y);
    if (faX != faY) {
        father[faX] = faY;
    }
}
bool cmp(int a, int b) { return a > b; }
int main() {
    freopen("in.txt", "r", stdin);
    int n, cnt = 0;
    int hobby[1010] = {0};
    cin >> n;
    father.resize(n + 1);
    isRoot.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int m, t;
        char c;
        cin >> m >> c;
        for (int j = 0; j < m; j++) {
            cin >> t;
            if (hobby[t] == 0) {
                hobby[t] = i;
            }
            Union(i, find(hobby[t]));
        }
    }
    for (int i = 1; i <= n; i++) isRoot[find(i)]++;
    for (int i = 1; i <= n; i++) {
        if (isRoot[i] != 0) cnt++;
    }
    cout << cnt << endl;
    sort(isRoot.begin(), isRoot.end(), cmp);
    for (int i = 0; i < cnt; i++) {
        cout << isRoot[i];
        if (i != cnt - 1) cout << " ";
    }
    cout << endl;
    return 0;
}