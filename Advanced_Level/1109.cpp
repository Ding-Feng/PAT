#include <bits/stdc++.h>
using namespace std;

struct student {
    string name;
    int high;
};
bool cmp(student a, student b) {
    if (a.high != b.high) {
        return a.high > b.high;
    } else {
        return a.name < b.name;
    }
}

int main(void) {
    // freopen("in.txt", "r", stdin);
    int n, k, high;
    string name;
    student stu[10010];
    cin >> n >> k;
    int num = n / k;
    int last = n - n / k * (k - 1);
    for (int i = 0; i < n; i++) {
        cin >> name >> high;
        stu[i].name = name;
        stu[i].high = high;
    }
    sort(stu, stu + n, cmp);
    for (int j = last / 2; j > 0; j--) {
        if (j != last / 2) cout << ' ';
        cout << stu[2 * j - 1].name;
    }
    for (int j = 0; j < (last / 2 + last % 2); j++) {
        if (num != 1) cout << ' ';
        cout << stu[2 * j].name;
    }
    cout << endl;
    for (int i = 0; i < k - 1; i++) {
        for (int j = num / 2; j > 0; j--) {
            if (j != num / 2) cout << ' ';
            cout << stu[2 * j - 1 + last + i * num].name;
        }
        for (int j = 0; j < (num / 2 + num % 2); j++) {
            if (num != 1) cout << ' ';
            cout << stu[2 * j + last + i * num].name;
        }
        cout << endl;
    }
    return 0;
}
