#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
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
vector<node*>tmp_path;
void printorder(node* root)
{
    if(root->left==NULL&&root->right==NULL)
    {
        for(int i=0;i<tmp_path.size();i++)
        {
		    if(i==0) printf("%d",tmp_path[i]->data);
		    else printf(" %d",tmp_path[i]->data);
	    }
        
        printf("\n");
    }
    else{
        if(root->right!=NULL)
        {
            tmp_path.push_back(root->right);
            printorder(root->right);
            tmp_path.pop_back();
        }
        if(root->left!=NULL)
        {
            tmp_path.push_back(root->left);
            printorder(root->left);
            tmp_path.pop_back();
        }
    }
}
int main()
{
    scanf("%d",&n);
    t = 1;
    while(t--)
    {
        first_flag = 0;
        struct node* root = NULL;
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        root = buildTree(root);
        tmp_path.push_back(root);
        printorder(root);
        if(isMaxHeap(root)) printf("Max Heap");
        else if(isMinHeap(root)) printf("Min Heap");
        else printf("Not Heap");
        if(t!=0) printf("\n");
    }
}