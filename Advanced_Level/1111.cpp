#include <bits/stdc++.h>
using namespace std;

const int inf = 999999999;
const int maxn = 510;
int n, m, s, d;
int minCost = inf, minCount = maxn;
int G[maxn][maxn];
int T[maxn][maxn];
int dis[maxn], t[maxn], num[maxn];
bool vis[maxn];
vector<int> pre[maxn], tmp, path;
vector<int> preT[maxn], tmpT, pathT;

void Dijkstra(int s) {
    fill(vis, vis + maxn, false);
    fill(dis, dis + maxn, inf);
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] < min) {
                u = j;
                min = dis[j];
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
void DijkstraTime(int s) {
    fill(vis, vis + maxn, false);
    fill(t, t + maxn, inf);
    t[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = inf;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && t[j] < min) {
                u = j;
                min = t[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && T[u][v] != inf) {
                if (t[u] + T[u][v] < t[v]) {
                    t[v] = t[u] + T[u][v];
                    preT[v].clear();
                    preT[v].push_back(u);
                } else if (t[u] + T[u][v] == t[v]) {
                    preT[v].push_back(u);
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
            pathCost += T[tmp[i]][tmp[i - 1]];
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
void DFST(int v) {
    tmpT.push_back(v);
    if (v == s) {
        int cnt = tmpT.size();
        if (cnt < minCount) {
            minCount = cnt;
            pathT = tmpT;
        }
        tmpT.pop_back();
        return;
    }
    for (int i = 0; i < preT[v].size(); i++) {
        DFST(preT[v][i]);
    }
    tmpT.pop_back();
}
int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    fill(G[0], G[0] + maxn * maxn, inf);
    fill(T[0], T[0] + maxn * maxn, inf);
    for (int i = 0; i < m; i++) {
        int a, b, isway, len, time;
        cin >> a >> b;
        cin >> isway >> len >> time;
        if (isway) {
            G[a][b] = len;
        } else {
            G[a][b] = G[b][a] = len;
        }
        T[a][b] = T[b][a] = time;
    }
    cin >> s >> d;
    Dijkstra(s);
    DFS(d);
    DijkstraTime(s);
    DFST(d);
    if (path != pathT) {
        cout << "Distance = " << dis[d] << ": ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;

        cout << "Time = " << t[d] << ": ";
        for (int i = pathT.size() - 1; i >= 0; i--) {
            cout << pathT[i];
            if (i != 0) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "Distance = " << dis[d] << "; ";
        cout << "Time = " << t[d] << ": ";
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i !=0) cout << " -> ";
        }
        cout << endl;
    }
    return 0;
}