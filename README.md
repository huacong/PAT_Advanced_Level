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
| 最短路径       | A1003 A1018 A1030 A1072 A1087                                |
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

    ```c++
    int edge[maxn][maxn];
    权图：memset(edge, 0x7f, sizeof(edge));//该函数是按字节进行赋值，将0x7f(01111111)赋值给edge的每一个字节
    无权图：memset(edge, 0, sizeof(edge));
    edge[u][v] = weight or 1
    edge[v][u] = weight or 1
    ```

  - 数组模拟邻接表存储

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

**题1034**

使用vector数组来存图并不是很合适，于是采用常规的邻接矩阵

最多有一千条通话记录，因此最多有两千个结点

**对于map的尝试，可以在string和int之间切换自如** 

两种做法

- DFS+图的遍历
- 并查集
