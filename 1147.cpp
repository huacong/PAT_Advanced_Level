#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int t,n;
struct node{
    int data;
    struct node *left;
    struct node *right;
};

const int maxn = 1e3+20;
int num[maxn];
node* buildTree(node* root)
{
    int i=0;
    queue<node*>q;
    root = new node();
    root->data = num[i];
    root->left = NULL;
    root->right = NULL;
    q.push(root);
    while(!q.empty())
    {
        node* tmp = q.front();q.pop();
        if(i+1<n) 
        {
            struct node* tmp_left = new node();
            tmp_left->data = num[i+1];
            tmp_left->left = NULL;
            tmp_left->right = NULL;
            tmp->left = tmp_left;
            q.push(tmp_left);
            i = i+1;
        }
        if(i+1<n) 
        {
            struct node* tmp_right = new node();
            tmp_right->data = num[i+1];
            tmp_right->left = NULL;
            tmp_right->right = NULL;
            tmp->right = tmp_right;
            q.push(tmp_right);
            i = i+1;
        }
    }
    return root;
}
bool isMaxHeap(node* root)
{
    bool flag_left = false;
    bool flag_right = false;
    if(root->left!=NULL)
        flag_left = (root->data>=root->left->data) && isMaxHeap(root->left); 
    else flag_left = true;
    if(root->right!=NULL)
        flag_right = (root->data>=root->right->data) && isMaxHeap(root->right); 
    else flag_right = true;
    return flag_left&&flag_right;
}
bool isMinHeap(node* root)
{
    bool flag_left = false;
    bool flag_right = false;
    if(root->left!=NULL)
        flag_left = (root->data<=root->left->data) && isMinHeap(root->left); 
    else flag_left = true;
    if(root->right!=NULL)
        flag_right = (root->data<=root->right->data) && isMinHeap(root->right); 
    else flag_right = true;
    return flag_left&&flag_right;
}
int first_flag = 0;
void postorder(node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        if(first_flag==0)
        {
            printf("%d",root->data);
            first_flag = 1;
        }
        else printf(" %d",root->data);
    }
}
int main()
{
    scanf("%d%d",&t,&n);
    while(t--)
    {
        first_flag = 0;
        struct node* root = NULL;
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        root = buildTree(root);
        if(isMaxHeap(root)) printf("Max Heap\n");
        else if(isMinHeap(root)) printf("Min Heap\n");
        else printf("Not Heap\n");
        postorder(root);
        if(t!=0) printf("\n");
    }
}