#include <algorithm>
using namespace std;
vector<int> fa;
class UnionFind {
   private:
    int* id;
    int count;

   public:
    UnionFind(int n) {
        count = n;
        id = new int[n];
    }
};
int find(int x) {
    if (x != fa[x]) {
        fa[x] = find(fa[x]);  //回溯时的压缩路径
    }
    return fa[x];
    //从x结点搜索到祖先结点所经过的结点都指向该祖先结点
    //会导致栈溢出
    //路径压缩
    int a = x;
    while (x != fa[x]) x = fa[x];
    while (a != fa[a]) {
        int t = a;
        a = fa[a];
        fa[t] = x;
    }
    return x;
}
void Union(int a, int b) {
    int faA = fa[a];
    int faB = fa[b];
    if (faA != faB) fa[faA] = faB;
}

int main(int argc, char const* argv[]) { return 0; }
