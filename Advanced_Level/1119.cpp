#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> in;
bool Unique = true;
struct node {
    int val;
    node *left, *right;
    node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void inorder(node* root) {
    if (root) {
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    return;
}
int preIndex = 0, postIndex = 0;
// cite from LeetCode  so exciting
node* build(int* pre, int* post) {
    node* root = new node(pre[preIndex++]);
    if (root->val != post[postIndex]) root->left = build(pre, post);
    if (root->val != post[postIndex]) root->right = build(pre, post);
    postIndex++;
    return root;
}
void check(node* root) {
    if (!root) return;
    if (root) {
        if ((root->left && !root->right) || (!root->left && root->right)) {
            Unique = false;
        } else {
            check(root->left);
            check(root->right);
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);
    cin >> n;
    int pre[n], post[n];
    for (int i = 0; i < n; i++) cin >> pre[i];
    for (int i = 0; i < n; i++) cin >> post[i];
    node* root = build(pre, post);
    check(root);
    if (Unique) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    inorder(root);
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << in[i];
    }
    cout << endl;
    return 0;
}
