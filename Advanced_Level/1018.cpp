#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
const int inf = 99999999;
int cmax, n, s, m;
int graph[maxn][maxn], num[maxn], dis[maxn], w[maxn];
bool vis[maxn];
int minNeed = inf, minBack = inf;
vector<int> pre[maxn], path, tmp;
void Dijkstra(int s) {
    fill(dis, dis + maxn, inf);
    dis[s] = 0;
    for (int i = 0; i <= n; i++) {
        int u = -1, min = inf;
        for (int j = 0; j <= n; j++) {
            if (!vis[j] && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v <= n; v++) {
            if (!vis[v] && graph[u][v] != inf) {
                if (dis[u] + graph[u][v] < dis[v]) {
                    dis[v] = dis[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + graph[u][v] == dis[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void dfs(int u) {
    tmp.push_back(u);
    if (u == 0) {
        int need = 0, back = 0;
        for (int i = tmp.size() - 1; i >= 0; i--) {
            int id = tmp[i];
            if (w[id] > 0) {
                back += w[id];
            } else {
                if (back + w[id] > 0) {
                    back += w[id];
                } else {
                    need += (0 - w[id] - back);
                    back = 0;
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minBack = back;
            path = tmp;
        } else if (need == minNeed && back < minBack) {
            minBack = back;
            path = tmp;
        }
    }
    for (int i = 0; i < pre[u].size(); i++) {
        dfs(pre[u][i]);
    }
    tmp.pop_back();
}
int main() {
    freopen("in.txt", "r", stdin);
    fill(graph[0], graph[0] + maxn * maxn, inf);
    cin >> cmax >> n >> s >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        w[i] = t - cmax / 2;
    }
    for (int i = 0; i < m; i++) {
        int s1, s2, t;
        cin >> s1 >> s2 >> t;
        graph[s1][s2] = graph[s2][s1] = t;
    }
    Dijkstra(0);
    dfs(s);
    cout<<minNeed<<" ";
    for (int i = path.size() - 1; i >= 0; i--){
        cout<<path[i];
        if(i!=0) cout<<"->";
    }
    cout<<" "<<minBack<<endl;
    return 0;
}