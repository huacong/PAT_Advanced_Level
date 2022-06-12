#include<cstdio>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
map<int,int>id2num;
map<int,int>num2id;
const int maxn = 1e3+20;
const int maxx = 1e4+20;
int father[maxx];
int set[maxn];
int num = 0;
// int id_to_num(int id)
// {
//     if(id2num[id]==0)
//     {
//         id2num[id] = ++num;
//         num2id[num] = id;
//         return num;
//     }
//     return id2num[id];
// }
struct data_node{
    int id;
    int fid;int mid;int k;
    int child[10];int set;int area;
}tmp_data[maxn];
struct node{
    int id;
    int people;
    double set;
    double area;
    int flag;
}ans[maxx];
bool cmp(node a,node b)
{
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int n;
int vis[maxx];
int find(int x)
{
    if(father[x]==x) return x;
    return father[x] = find(father[x]);
}
void Union(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx<fy) father[fy] = fx;
    else if(fx>fy) father[fx] = fy;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<maxx;i++) father[i] = i;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d%d",&tmp_data[i].id,&tmp_data[i].fid,&tmp_data[i].mid,&tmp_data[i].k);
        vis[tmp_data[i].id] = 1;
        if(tmp_data[i].fid!=-1)
        {
            Union(tmp_data[i].id,tmp_data[i].fid);
            vis[tmp_data[i].fid] = 1;
        }
        if(tmp_data[i].mid!=-1)
        {
            Union(tmp_data[i].id,tmp_data[i].mid);
            vis[tmp_data[i].mid] = 1;
        }
        for(int j=0;j<tmp_data[i].k;j++)
        {
            scanf("%d",&tmp_data[i].child[j]);
            Union(tmp_data[i].id,tmp_data[i].child[j]);
            vis[tmp_data[i].child[j]] = 1;
        }
        scanf("%d%d",&tmp_data[i].set,&tmp_data[i].area);
    }
    
    for(int i=1;i<=n;i++)
    {
        int tid = find(tmp_data[i].id);
        ans[tid].id = tid;
        ans[tid].set += tmp_data[i].set;
        ans[tid].area += tmp_data[i].area;
        ans[tid].flag = 1; // 一个tmp_data代表一个家族
    }
    
    int cnt = 0;
    for(int i=1;i<maxx;i++)
    {
        if(vis[i]==1) ans[find(i)].people++;
        if(ans[i].flag) cnt++;
    }
   
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].set = (double)(ans[i].set * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp);
    
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].set, ans[i].area);
    return 0;


    // for(int i=1;i<=n;i++)
    // {
    //     int id; scanf("%d",&id);
    //     int id_num = id_to_num(id);
    //     int fid,mid;scanf("%d%d",&fid,&mid);
    //     int f_num = id_to_num(fid);
    //     int m_num = id_to_num(mid);
    //     if(find(f_num)!=find(m_num)) father[find(f_num)] = find(m_num);
    //     if(find(f_num)!=find(id_num)) father[find(id_num)] = find(f_num);
    //     int k; scanf("%d",&k);
    //     for(int i=0;i<k;i++)
    //     {
    //         int a;scanf("%d",&a);
    //         int child_num = id_to_num(a);
    //         if(find(id_num)!=find(child_num)) father[find(child_num)] = find(id_num);
    //     }
    //     scanf("%d")
    // }

}