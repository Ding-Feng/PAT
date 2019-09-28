#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* left;
    node* right;
}*root;
vector<int> L,In;
void level(node* root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();
        L.push_back(tmp->val);
        q.pop();
        if(tmp->left)q.push(tmp->left);
        if(tmp->right)q.push(tmp->right);
    }
}
void in(node* root){
    if(root){
        in(root->left);
        In.push_back(root->val);
        in(root->right);
    }
}
node* invert(node* root){
    if(root){
        invert(root->left);
        invert(root->right);
        swap(root->left,root->right);
    }
    return root;
}
int main(){
    freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    vector<node*> v(n);
    for(int i=0;i<n;i++){
        v[i]=new node();
        v[i]->val=i;
    }
    for(int i=0;i<n;i++){
        char lc,rc;
        cin>>lc>>rc;
        if(lc=='-') v[i]->left = NULL;
        else  v[i]->left = v[lc-'0'];
        if(rc=='-') v[i]->right = NULL;
        else  v[i]->right = v[rc-'0'];
    }
    vector<int> findRoot(n);
    for(int i=0;i<n;i++){
        // cout<<v[i]->val<<endl;
        if(v[i]->left){
            // cout<<v[i]->left->val;
            findRoot[v[i]->left->val]++;
        }
        if(v[i]->right){
            // cout<<v[i]->right->val;
            findRoot[v[i]->right->val]++;
        }
    }
    // for(auto it:findRoot) cout<<it;
    for(int i=0;i<n;i++){
        if(findRoot[i]==0){
            root = v[i];
        }
    }
    root=invert(root);
    level(root);
    in(root);
    for(int i=0;i<L.size();i++){
        if(i!=0) cout<<" ";
        cout<<L[i];
    }
    cout<<endl;
    for(int i=0;i<In.size();i++){
        if(i!=0) cout<<" ";
        cout<<In[i];
    }
    cout<<endl;    
    return 0;
}