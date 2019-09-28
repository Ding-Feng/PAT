#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int main() {
    freopen("in.txt", "r", stdin);
    cin >> n;
    vector<int> v(n), ans;
    int back[n], forward[n];
    // back[i] means the biggest in [0,i)
    // forward[i] means the smallest in (i,n]
    for (int i = 0; i < n; i++) cin >> v[i];
    back[0] = v[0];
    forward[n - 1] = v[n - 1];
    for (int i = 1; i < n; i++) back[i] = max(back[i - 1], v[i]);
    for (int i = n - 2; i >= 0; i--) forward[i] = min(forward[i + 1], v[i]);
    for (int i = 0; i < n; i++) {
        if (v[i] >= back[i] && v[i] <= forward[i]) ans.push_back(v[i]);
    }
    if (ans.size() == 0)
        cout << ans.size() << endl << endl;
    else {
        cout << ans.size() << endl;
        for (auto it = ans.begin(); it != ans.end(); it++) {
            if (it != ans.begin()) cout << " ";
            cout << *it;
        }
    }
    return 0;
}