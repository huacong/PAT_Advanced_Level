#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
const int maxn = 205;
int weight[maxn];
int happ[maxn];
const int maxx = 4e4+20;
const int INF = 0x3f3f3f3f;
int dist[maxn];
int vis[maxn];
struct Edge{
    int to;int dis;int next;
}edge[maxx];
int head[maxn];
int road[maxn];
int num_edge;
void add_edge(int from,int to,int dis)
{
    edge[++num_edge].next = head[from];
    edge[num_edge].to = to;
    edge[num_edge].dis = dis;
    head[from] = num_edge;
}
map<string,int>str2int;
map<int,string>int2str;
vector<int>pre[maxn];
int num;
int city2int(string city)
{
    if(str2int[city]==0)
    {
        str2int[city] = ++num;
        int2str[num]  = city;
        return num;
    }
    return str2int[city];
}
int n,m;
int s;
void dij(int s)
{
    for(int i=1;i<=num;i++) dist[i] = INF;
    dist[s] = 0;
    // road[s] = 1;
    for(int j=1;j<=num;j++)
    {
        int min_value = INF;
        int k = -1;
        for(int u=1;u<=num;u++)
        {
            if(!vis[u]&&dist[u]<min_value)
            {
                min_value = dist[u];
                k = u;
            }
        }
        if(k==-1) break;
        vis[k] = 1;
        for(int u=head[k];u!=0;u=edge[u].next)
        {
            int v = edge[u].to;
            int dis = edge[u].dis;
            if(!vis[v])
            {
                if(dist[v]>dist[k]+dis)
                {
                    dist[v] = dist[k] + dis;
                    happ[v] = happ[k] + weight[v];
                    pre[v].clear();
                    pre[v].push_back(k);
                }
                else if(dist[v]==dist[k]+dis)
                {
                    pre[v].push_back(k);
                    //除了得到最大快乐，最小路径，以及最短路径以外，还要得到最短平均路径。
                    //不如将他们记录下来
                }
            }
        }
    }
}
int ans_cnt_path = 0;
int ans_sum;
int ans_ave;
vector<int>tmp_path;
vector<int>ans_path;
void cnt_path(int u)
{
    if(u==s)
    {
        ans_cnt_path++;
        tmp_path.push_back(u);
        int tmp_ave = 0;
        int tmp_sum = 0;
        // for(int i=tmp_path.size()-1;i>=0;i--)
        // {
        //     if(i>0)  cout<<int2str[tmp_path[i]]<<"->";
        //     else cout<<int2str[tmp_path[i]]<<endl;
        // }
        for(int i=tmp_path.size()-1;i>=0;i--)
            tmp_sum+=weight[tmp_path[i]];
        tmp_ave = tmp_sum/(tmp_path.size()-1);
        if(tmp_sum>ans_sum)
        {
            ans_sum = tmp_sum;
            ans_ave = tmp_ave;
            ans_path = tmp_path;
        }
        else if(tmp_sum==ans_sum&&tmp_ave>ans_ave)
        {
            ans_sum = tmp_sum;
            ans_ave = tmp_ave;
            ans_path = tmp_path;
        }
        tmp_path.pop_back();
    }
    tmp_path.push_back(u);
    for(int i=0;i<pre[u].size();i++)
    {
        cnt_path(pre[u][i]);
    }
    tmp_path.pop_back();
}
int main()
{
    string start;
    cin>>n>>m>>start;
    s = city2int(start);
    for(int i=1;i<n;i++)
    {
        string city;int happiness;
        cin>>city>>happiness;
        //printf("%d\n",city2int(city));
        weight[city2int(city)] = happiness;
    }
    //printf("%d %d\n",num,n);
    for(int i=1;i<=m;i++)
    {
        string city1,city2; int dis;
        cin>>city1>>city2>>dis;
        add_edge(city2int(city1),city2int(city2),dis);
        add_edge(city2int(city2),city2int(city1),dis);
    }
    int e = city2int("ROM");
    dij(s);
    cnt_path(e); 
    printf("%d %d %d %d\n",ans_cnt_path,dist[e],ans_sum,ans_ave);
    for(int i=ans_path.size()-1;i>=0;i--)
    {
        if(i>0)  cout<<int2str[ans_path[i]]<<"->";
        else cout<<int2str[ans_path[i]];
    }
    return 0;
}
