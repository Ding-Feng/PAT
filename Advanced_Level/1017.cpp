#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int come, time;
};
bool cmp(node a, node b) { return a.come < b.come; }
int findMin(vector<int> v) {
    int min = v[0], index = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] < min) {
            min = v[i];
            index = i;
        }
    }
    return index;
}
int main() {
    freopen("in.txt", "r", stdin);
    int n, k;
    double result = 0;
    cin >> n >> k;
    vector<node> v;
    vector<int> window(k, 8 * 60 * 60);

    for (int i = 0; i < n; i++) {
        int hh, mm, ss, time;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &time);
        int comeTime = hh * 60 * 60 + mm * 60 + ss;
        if (comeTime > 61200) continue;
        node tmp;
        tmp.come = comeTime;
        tmp.time = time * 60;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    //先来先服务
    for (int i = 0; i < v.size(); i++) {
        int tmpIndex = 0;
        tmpIndex = findMin(window);
        if (window[tmpIndex] <= v[i].come) {
            window[tmpIndex] = v[i].come + v[i].time;
        } else {
            result += (window[tmpIndex] - v[i].come);
            window[tmpIndex] += v[i].time;
        }
    }
    if (v.size() == 0) {
        cout << "0.0";
    } else {
        printf("%.1f", result / 60.0 / v.size());
    }

    return 0;
}