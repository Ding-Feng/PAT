#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int inf = 0x9999999;
int n, m, c1, c2;
int weight[maxn], dis[maxn];
bool vis[maxn];
int graph[maxn][maxn];
int num[maxn], w[maxn];
void Dijkstra(int c1) {
    fill(dis, dis + maxn, inf);
    fill(w, w + maxn, 0);
    fill(num, num + maxn, 0);
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for (int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for (int j = 0; j < n; j++) {
            if (vis[j] == false && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (vis[v] == false && graph[u][v] != inf) {
                if (dis[u] + graph[u][v] < dis[v]) {
                    dis[v] = dis[u] + graph[u][v];
                    w[v] = weight[v] + w[u];
                    num[v] = num[u];
                } else if (dis[u] + graph[u][v] == dis[v]) {
                    if (weight[v] + w[u] > w[v]) {
                        w[v] = weight[v] + w[u];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
};
int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    fill(graph[0], graph[0] + maxn * maxn, inf);
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a][b] = graph[b][a] = l;
    }
    Dijkstra(c1);
    cout << num[c2] << " " << w[c2] << endl;

    return 0;
}