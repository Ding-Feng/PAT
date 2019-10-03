#include <bits/stdc++.h>
using namespace std;

const int inf = 99999999;
const int maxn = 510;

int n, m, s, d;
int minCost = inf;
int G[maxn][maxn];
int C[maxn][maxn];
int dis[maxn];
bool vis[maxn];
vector<int> pre[maxn], path, tmp;

void Dijkstra(int s) {
    fill(dis, dis + maxn, inf);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < min) {
                min = dis[j];
                u = j;
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && G[u][v] != inf) {
                if (dis[u] + G[u][v] < dis[v]) {
                    dis[v] = dis[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + G[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int v) {
    tmp.push_back(v);
    if (v == s) {
        int pathCost = 0;
        for (int i = tmp.size() - 1; i > 0; i--) {
            pathCost += C[tmp[i]][tmp[i - 1]];
        }
        if (pathCost < minCost) {
            minCost = pathCost;
            path = tmp;
        }
        tmp.pop_back();
        return;
    }
    for (int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tmp.pop_back();
}
int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m >> s >> d;
    fill(G[0], G[0] + maxn * maxn, inf);
    for (int i = 0; i < m; i++) {
        int a, b, dis, cost;
        cin >> a >> b >> dis >> cost;
        G[a][b] = G[b][a] = dis;
        C[a][b] = C[b][a] = cost;
    }
    Dijkstra(s);
    DFS(d);
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << dis[d] << " " << minCost << endl;
    return 0;
}