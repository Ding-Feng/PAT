#include <bits/stdc++.h>
using namespace std;

int m, n, l, t;
int arr[1300][130][80];
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
bool visit[1300][130][80];
bool judge(int x, int y, int z) {
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if (arr[x][y][z] == 0 || visit[x][y][z] == true) return false;
    return true;
}
struct node {
    int x, y, z;
    node(int a, int b, int c) { x = a, y = b, z = c; }
};
int bfs(int x, int y, int z) {
    int cnt = 0;
    node tmp(x, y, z);
    queue<node> q;
    q.push(tmp);
    visit[x][y][z] = true;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 6; i++) {
            int tx, ty, tz;
            tx = now.x + X[i];
            ty = now.y + Y[i];
            tz = now.z + Z[i];
            if (judge(tx, ty, tz)) {
                visit[tx][ty][tz] = true;
                node tmp(tx, ty, tz);
                q.push(tmp);
            }
        }
    }

    if (cnt >= t) {
        return cnt;
    } else {
        return 0;
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    cin >> m >> n >> l >> t;
    int tmp;
    for (int h = 0; h < l; h++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j][h];
            }
        }
    }
    int ans = 0;
    for (int h = 0; h < l; h++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j][h] == 1 && visit[i][j][h] == false)
                    ans += bfs(i, j, h);
            }
        }
    }
    cout << ans;
    return 0;
}