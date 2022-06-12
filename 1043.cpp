#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1e3+20;
vector<int>pre,post,str;
int n;
// struct node{
//     int data;
//     int left;
//     int right;
// }tree[maxn];//
struct node{
    int data;
    struct node *left, *right;
};
struct node *root = NULL;
node* insert(node* root, int data)
{
    if(root==NULL){
        root = new node();
        root->data = data;
        root->left = root->right = NULL;
        return root;
    }
    else if(data<root->data)
    {
        root->left = insert(root->left,data);
        return root;
    }
    else if(data>=root->data)
    {
        root->right = insert(root->right,data);
        return root;
    }
}
void preorder(node *root)
{
    if(root!=NULL)
    {
        pre.push_back(root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void preorder_mirror(node *root)
{
    if(root!=NULL)
    {
        pre.push_back(root->data);
        preorder_mirror(root->right);
        preorder_mirror(root->left);
    }
}
void postorder(node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        post.push_back(root->data);
    }
}
void postorder_mirror(node *root)
{
    if(root!=NULL)
    {
        postorder_mirror(root->right);
        postorder_mirror(root->left);
        post.push_back(root->data);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        str.push_back(tmp);
    }
    for(int i=0;i<n;i++) root = insert(root,str[i]);
    pre.clear();
    preorder(root);
    int i = 0;
    for(i=0;i<n;i++)
    {
        if(str[i]!=pre[i]) break;
    }
    if(i==n)
    {
        printf("YES\n");
        postorder(root);
        for(int j=0;j<n;j++) printf("%d ",post[j]);
        return 0;
    }
    pre.clear();
    preorder_mirror(root);
    for(i=0;i<n;i++)
    {
        if(str[i]!=pre[i]) break;
    }
    if(i==n)
    {
        printf("YES\n");
        postorder_mirror(root);
        for(int j=0;j<n;j++) printf("%d ",post[j]);
        return 0;
    }
    printf("NO");
    return 0;
}