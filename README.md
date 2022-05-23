# PAT Advanced Level



### 4.18 

#### 题1010 tag：二分

Result: 17/25  wrong answer

- 两个关键步骤，将 指定进制的string转换成十进制表示

- 查询指定的string能够表示成给定十进制数的**最小进制**

  最小进制数的寻找，典型**二分问题**， 下边界为string字符串中最大的数字表示，上边界为给定的十进制数！**要注意查询的是最小进制！** 

#### 题1013 tag：图论

题目大意：给出n个城市之间有相互连接的m条道路，当删除一个城市的时候，这个城市和其他道路的连接将同时去掉，问其他几个剩余的城市需要至少添加多少个路线才能让他们重新变为连通图。

solution：

- 采用**邻接矩阵**存储所有的边

- 查询这个连接图中所有的强连通分量。

  通过从一个点出发采用**DFS**遍历从它可以到达的所有顶点，这个过程的结束代表着已经遍历了一个强连通分量。在不同地点，重复此过程，查询强连通分量的个数。

```c++
void dfs(int u)
{
	visited[u] = 1;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0&&map[u][i]==1)
			dfs(i);
	}
}
```

### 4.19 

参照胡凡的《算法笔记》

|                |                                                              |
| -------------- | ------------------------------------------------------------ |
| 排序           | **A1012** A1016 **A1025** A1028 A1055 A1075 A1083 A1080 A1095 |
| 贪心           | A1070 A1033 A1037 A1067 A1038                                |
| 二分           | A1010 A1085 A1044 A1048                                      |
| 散列           | A1084 A1092 A1041 A1050 A1048                                |
| two pointers   | A1085 A1089 A1029 A1048                                      |
| 其他高效算法   | A1093 A1101                                                  |
| 简单数学       | A1008 A1049 A1104 A1069                                      |
| 分数的四则运算 | A1081 A1088                                                  |
| 素数           | A1015 A1078                                                  |
| 质因数分解     | A1096 A1059                                                  |
| 大整数运算     | A1023 A1024                                                  |
| 栈 stack       | A1051                                                        |
| 队列           | A1056                                                        |
| 链表处理       | A1032 A1052 A1097 A1074                                      |
| DFS            | A1103                                                        |
| BFS            | A1091                                                        |
| 二叉树的遍历   | A1020 A1086 A1102                                            |
| 树的遍历       | A1079 A1090 A1094 A1106 A1004 A1053                          |
| 二叉查找树     | A1043 A1064 A1090                                            |
| **并查集**     | **A1107**                                                    |
| 堆             | A1098                                                        |
| **图的遍历**   | **A1013** **A1021** **A1034** A1076                          |
| 最短路径       | **A1003** **A1018** **A1030** **A1072** **A1087**            |
| dp             | A1007 A1045 A1040 A1068                                      |
| 字符串hash     | A1040                                                        |
| kmp            | 无题，需要补充                                               |

**题1107** 

**并查集模板**

```c++

int find(int v)
{
    if(father[v]==v) return v;
    return father[v] = find(father[v]); //路径压缩，如果不进行路径压缩容易超时
    //如果不进行
}
void UNION(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx!=fy) father[fy] = fx;
}
void init()
{
    for(int i=1;i<=n;i++)
        father[i]=i;
}

```

**图论模板**

- 建立图

  图中点的数量表示为n 最大为maxn

  图中边的数量表示为e 最大为maxx

  - 邻接矩阵

    O($N^2$) 

    ```c++
    int edge[maxn][maxn];
    权图：memset(edge, 0x7f, sizeof(edge));//该函数是按字节进行赋值，将0x7f(01111111)赋值给edge的每一个字节
    无权图：memset(edge, 0, sizeof(edge));
    edge[u][v] = weight or 1
    edge[v][u] = weight or 1
    ```

  - 数组模拟邻接表存储

    O(N+M): 找反向边有一点困难

    小tips：0-1，2-3，4-5，6-7 对于无向图来说，其连续两个num_edge所对应的边互为反向边，因此只要让 num_edge对1进行异或运算，即可得到。

    ```c++
    struct Edge{
        int next; // 下一条边的编号
        int to; //这条边到达的顶点
        int dis; //这条边的长度
    }edge[maxx];
    int head[maxn];
    int num_edge;
    void add_edge(int from, int to, int dis)
    {
        edge[++num_edge].next = head[from];
        edge[num_edge].to = to;
        edge[num_edge].dis = dis;
        head[from] = num_edge;
    }
    ```

- 图的遍历

  - 深度优先遍历

    

  - 广度优先遍历



**题1021**

- 使用vector进行存图的模板总结

**题1034**

使用vector数组来存图并不是很合适，于是采用常规的邻接矩阵

最多有一千条通话记录，因此最多有两千个结点

**对于map的尝试，可以在string和int之间切换自如** 

两种做法

- DFS+图的遍历
- 并查集



### 4.20 

#### 拓扑排序

拓扑排序(Topological Sorting)算法，只适用于AOV网，有向无环图。

把AOV网中的所有前驱活动排成一个序列，使得每个活动的所有前驱活动都排在活动的前面，这个过程称为“拓扑排序”。所得到的活动序列成为“拓扑序列”。

**Process**

-  s1:选择一个入度为0的顶点并输出 din[u]==0
- s2:然后从AOV网中删除此顶点以及以此顶点为起点的所有关联边，让u相邻的所有顶点的入度减一
- s3:重复以上两步，直到不存在入度为0的顶点为止
- s4:若输出的顶点数小于AOV网中的顶点数，则输出“有回路信息”，否则输出的序列就是一种拓扑序
- s5:从第四步可以看出，拓扑排序可以用来判断一个有向图是否有环。只有有向无环图(DAG)才存在拓扑序列。

时间复杂度为$O(n+m)$ 

**模板**

- topological_sort_dfs：采用dfs遍历
- topological_sort_bfs：采用bfs遍历

**例题**

- 洛谷P1807最长路（url=https://www.luogu.com.cn/problem/P1807）

#### Floyed

对于floyed算法依然采用 邻接矩阵 map[maxn\][maxn]

#### Dijkstra

用来计算从一个点到其他所有点的最短路径的算法，是一种单源最短路径算法。它的时间复杂度是$O(N^2)$ ,它不能处理存在负边权的情况。

#### SPFA算法



### 4.21

#### 题1018 

- 使用vector数组进行图的存取
- 如何计算在边权和最小的最短路情况下，**使得这条路上的点权之和最小**
  - 在Dij时，**使用一个vector来保存prev，**  **prev[u]=v**，表示u的前驱节点，可能会有若干个。
  - 然后采用一个dfs，将这些可能的情况都考虑到，并最终从中选择一个点权最小的序列。！！！！重点，如何打印路径！



#### 题1030

- 使用数组模拟邻接表进行图的存取//使用vector数组进行图的存取
- 计算在距离最短路的情况下，这条路上的成本最短路
  - 层次判别！hierarchy condition！



### 4.23 

#### 题1072

16/30

#### 题1087

- 考虑所有可能的最短路情况，并将所有结果保存
- 采用dfs，遍历每一条路，类似1018，计算哪一条路具有最大的happiness以及最大的average happiness
- str 和 int之间利用map进行自由转换

#### 4.24 DP 动态规划
**背包问题**

- **01背包**：
  
    ```cpp
    优化以前:f[i][v] = max{f[i-1][v], f[i-1][v-w[i]]+c[i]}
    
    空间优化以后: f[v] = max{f[v],f[v-w[i]]+c[i]} // from v = max_weight to v = vol[i], v--
    ```
  
- **完全背包问题：** 对于第 $i$ 种物品可以选取任意件
- **多重背包问题：**
  
   对于第 $i$ 种物体，最多有 $n[i]$ 件可用，每件费用是  $w[i]$ ,价值是 $c[i]$。
   - 朴素做法： `f[j] = max(f[j],f[j-k*v[i]]+k*c[i]);`
   - 转化为01背包问题：  拆分的所有物体前面的系数均为1
   - 采用二进制的思想转为0-1背包：拆分的所有物体前面的系数均为$1$,$2$,$4$,...,$2^{k-1}$,$n[i]-2^k+1$,如果$n[i]$为13，则可以拆分为$1,2,4,6$
- 二维费用的背包问题
- **分组背包：**
  将所有给出的物体划分为若干组，每组中的物品都会有冲突,最多选择一件。
  
  ```cpp
  for 所有的组k
    for v=V...0
      for 所有的i属于组k
        f[v] = max{f[v],f[v-w[i]]+c[i]}
  // v from V to 0 的循环保证每一组内只有一个物体会被添加到背包中！
  ```

**动态规划经典问题**





**线性DP**

**区间DP**

- 合并石子：
- 乘积最大

**计数类DP**

**数位统计DP**

**状态压缩DP**

**树形DP**

**记忆化搜索**



#### 4.28 二叉树

**关于二叉树的一些性质**

- 二叉树中层数为 $i$ 的节点至多有$2^i$个, $i\ge0$



**二叉树的遍历**

![image-20220430170847370](C:\Users\Huac\AppData\Roaming\Typora\typora-user-images\image-20220430170847370.png)

- 中根遍历：左（根）右
- 先根遍历：（根）左右
- 后根遍历：左右（根）
- 层次遍历

给定前序和中序可以求出后序

给定后序和中序可以求出前序

给定前序和后序，中序不唯一

洛谷二叉树整理

| 题目大意                                                     | 解题思路                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| P4715 淘汰赛 给定一棵二叉树的的所有叶节点，给定叶子之间的大小关系，按照此关系生成一个满二叉树，并判断谁是根节点下面的节点。 | 模拟/技巧(分成两段，每段最大值相比较选出一二名)              |
| P4913 二叉树深度 根据题目要求建立一棵二叉树，并计算其深度    | DFS深度优先遍历，每深一层，深度加一                          |
| P1827 已知中序遍历和前序遍历，求后序遍历                     | 前序遍历去的第一个始终是根，在中序遍历中找到根分为两个子树，把根压入stack，因为是后序遍历，根要最后输出 |
| P1364 医院设置 每个点的权重代表居民总数，思考医院建在哪里可以使得全体居民的路程之和最小。 | 当医院的位置确定后，每个点到医院有且仅有一条路可以走，采用Dij计算之间的距离，然后乘以点的权重。 |
| P1229 已知前序遍历和后序遍历，求可能的中序遍历序列的总数     |                                                              |
| P1305 直接输出其前序遍历                                     |                                                              |
| P1030 已知后序遍历和中序遍历，求前序遍历                     |                                                              |
| P3884 求最大深度，求最大宽度，以及LCA算法，求最小公共祖先    |                                                              |
| P3379 LCA朴素算法和倍增算法的板子题                          |                                                              |



**LCA最小公共祖先算法** 寻找最小公共祖先





#### 4.29 最小生成树（MST）

Kruskal 算法yyds！

| 题目大意 | 解题思路 |
| -------- | -------- |
| P3366    |          |
| P1991    |          |
| P1396    |          |
| P2121    |          |
| P1194    |          |
| P1195    |          |

#### 5.12 二分查找

| 题目大意 | 解题思路 |
| -------- | -------- |
| P2249    |          |
| P1991    |          |
| P1396    |          |
| P2121    |          |
| P1194    |          |
| P1195    |          |

**二分模板** 

对于有序数组，即一个单调不减序列，对于每次询问，输出这个数字在序列中第一次出现的编号 left-bound

对于有序数组，即一个单调不减序列，对于每次询问，输出这个数字在序列中最后一次出现的编号 right-bound

**C++自带的二分函数**

`lower_bound(a+1,a+n+1,x)`

lower_bound 返回序列中**第一个大于等于x**的数的地址，下边界

`p1 = lower_bound(a+1,a+n+1,x)-a` 对应第一个大于等于x的数的下标

`upper_bound(a+1,a+n+1,x)`

upper_bound返回序列中**第一个大于x**的数的地址，上边界

`p2=upper_bound(a+1,a+n+1,x)-a`对应第一个大于x的数的下标

**二分答案**

#### 5.13 贪心

P1106

#### 5.22 动态规划

动态规划的引入

#### 5.23 线性状态动态规划

**最长不下降子序列 LCS** 模板

- 朴素方法 时间复杂度 $O(n^2)$

  $dp[i]$ 代表截止到 $num[i]$ 的问题的解

- 维护单调数组，时间复杂度$O(n\log n)$

  维护一个单调数组，$dp[i]$代表长度为 $i$ 的最后一个元素。 



