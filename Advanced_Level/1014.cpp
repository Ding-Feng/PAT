#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int N, M, K, Q;

string NumToTime(int num) {
    if (num > 17 * 60) {
        return "Sorry";
    }
    int minute = num % 60;
    int hour = num / 60;
    string result = hour + ":" + minute;
    return result;
}
struct node {
    int beginTime;
    int endTime;
    vector<int> waitLine;
};
int main() {
    freopen("in.txt", "r", stdin);
    cin >> N >> M >> K >> Q;
    vector<int> customer(K + 1);
    vector<int> question;
    vector<node> windows(N + 1);
    int tmp;
    int start = 8 * 60;
    for (int i = 1; i <= K; i++) {
        cin >> tmp;
        customer[i] = tmp;
    }
    // input ending
    int index =1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (index<=K)
            {
                windows[j].waitLine.push_back(customer[index]);
            }
            
        }

        // find min in queue; push back; add time;
    }

    return 0;
}