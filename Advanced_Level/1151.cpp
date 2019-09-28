#include <bits/stdc++.h>
using namespace std;
struct node {
    int val;
    node* left;
    node* right;
    node(int n) {val = n;left = NULL;right = NULL;}
};
int mode;
node* LCA(node* root,int u,int v){
    if(!root || root->val==u || root->val == v) return root;
    node* left = LCA(root->left,u,v);
    node* right = LCA(root->right,u,v);
    if(left && right){
        mode = 1;
        return root;
    }
    return left?left:right;
}
int n;
node* root;
void Find(int* in,int u,int v){
    mode =0;
    bool flagU=false,flagV=false;
    for(int i=0;i<n;i++){
        if(in[i]==u) flagU=true;
        if(in[i]==v) flagV=true;
    }
    if(flagU && !flagV){
        printf("ERROR: %d is not found.\n",v);
    }else if (!flagU && flagV){
        printf("ERROR: %d is not found.\n",u);
    }else if(!flagU && !flagV){
        printf("ERROR: %d and %d are not found.\n",u,v);
    }else{
        // cout<<"lca"<<endl;
        node* ans=LCA(root,u,v);
        if(mode==1){
            printf("LCA of %d and %d is %d.\n",u,v,ans->val);
        }else{
            int t = ans->val == u ? v: u;
            printf("%d is an ancestor of %d.\n",ans->val,t);
        }
    }
    return ;
}
node* build(int preL, int preR, int inL, int inR, int* in,
            int* pre) {
    if(preL==preR) return NULL;
    node* root = new node(pre[preL]);
    int index=0;
    while (inL+index != inR)
    {
        if(in[inL+index]==pre[preL]) break;
        index++;
    }
    root->left =build(preL+1,preL+1+index,inL,inL+index,in,pre);
    root->right=build(preL+index+1,preR,inL+index+1,inR,in,pre);
    return root;
}
int main() {
    freopen("in.txt","r",stdin);
    int m;
    cin >> m >> n;
    // n inorder && preorder
    // m lines u&v to judge
    int in[n],pre[n];
    for (int i = 0; i < n; i++) cin >> in[i];
    for (int i = 0; i < n; i++) cin >> pre[i];
    root = build(0, n, 0, n, in, pre);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        Find(in,u,v);
    }
    return 0;
}