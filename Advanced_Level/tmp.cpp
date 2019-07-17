#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 510;
const int inf = 99999999;
int n, m, s, t;
int weight[maxn];
int dis[maxn], w[maxn], num[maxn];
int G[maxn][maxn];
bool vis[maxn] = {false};
vector<int> pre[maxn], path, tmp;
int Max = -1;
void Dijkstra(int s) {
    num[s] = 1;
    dis[s] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && dis[j] != inf) {
                u = j;
                minn = dis[j];
            }
        }
        if (u == -1) break;
        for (int v = 0; v < n; v++) {
            if (!vis[v] && G[u][v] != inf) {
                if (dis[u] + G[u][v] < dis[v]) {
                    num[v] = num[s];
                    dis[v] = dis[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (dis[u] + G[u][v] == dis[v]) {
                    num[v] = num[u] + num[v];
                }
            }
        }
    }
}