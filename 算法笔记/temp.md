## 树的中心

```c++
/*
给定一棵树，树中包含 n 个结点（编号1~n）和 n−1 条无向边，每条边都有一个权值。

请你在树中找到一个点，使得该点到树中其他结点的最远距离最近。

输入格式
第一行包含整数 n。

接下来 n−1 行，每行包含三个整数 ai,bi,ci，表示点 ai 和 bi 之间存在一条权值为 ci 的边。

输出格式
输出一个整数，表示所求点到树中其他结点的最远距离。

数据范围
1≤n≤10000,
1≤ai,bi≤n,
1≤ci≤105
输入样例：
5 
2 1 1 
3 2 1 
4 3 1 
5 1 1
输出样例：
2
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e4+10, M = N*2, INF=0x3f3f3f3f;
int d1[N], d2[N], p1[N], p2[N], up[N];
int h[N], e[M], ne[M], w[M], idx;
int n;
void add(int a, int b, int c);
int dfs_d(int u, int father);
void dfs_u(int u, int father);

int main()
{
    cin>>n;
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;++i)
    {
        int a, b, c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs_d(1,-1);
    dfs_u(1,-1);
    int res=INF;
    for(int i=1;i<=n;++i)
    {
        res=min(res,max(d1[i],up[i]));
    }
    cout<<res<<endl;
    return 0;
}

void add(int a, int b, int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx++;
}

int dfs_d(int u, int father)
{
    d1[u] = d2[u] = -INF;
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(j == father)
            continue;
        int d=dfs_d(j,u)+w[i];
        if(d>d1[u])
        {
            d2[u]=d1[u];
            d1[u]=d;
            p2[u]=p1[u];
            p1[u]=j;
        }
        else if(d>d2[u])
        {
            d2[u]=d;
            p2[u]=j;
        }
    }
    if(d1[u] == -INF)
        d1[u]=d2[u]=0;
    
    return d1[u];
}

void dfs_u(int u, int father)
{
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(j==father)
            continue;
        if(p1[u]==j)
            up[j]=max(up[u],d2[u])+w[i];
        else
            up[j]=max(up[u],d1[u])+w[i];
    dfs_u(j,u);
    }
}
```

## 树的最长直径

```c++
/*
给定一棵树，树中包含 n 个结点（编号1~n）和 n−1 条无向边，每条边都有一个权值。

现在请你找到树中的一条最长路径。

换句话说，要找到一条路径，使得使得路径两端的点的距离最远。

注意：路径中可以只包含一个点。

输入格式
第一行包含整数 n。

接下来 n−1 行，每行包含三个整数 ai,bi,ci，表示点 ai 和 bi 之间存在一条权值为 ci 的边。

输出格式
输出一个整数，表示树的最长路径的长度。

数据范围
1≤n≤10000,
1≤ai,bi≤n,
−105≤ci≤105
输入样例：
6
5 1 6
1 4 5
6 3 9
2 6 8
6 1 7
输出样例：
22
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 10010, M = N * 2;
int h[N], e[M], w[M], ne[M], idx;
void add(int a, int b, int c)  // 添加一条边a->b，边权为c
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}
int n, ans;
int dfs(int u, int father)
{
    int dist=0;
    int d1=0, d2=0;
    
    for (int i = h[u]; i != -1; i = ne[i] )
    {
        int j=e[i];
        if(j==father)
            continue;
        int d=dfs(j, u) + w[i];
        dist=max(dist, d);
        if(d>=d1)
        {
            d2=d1;
            d1=d;
        }
        else if(d>d2)
            d2=d;
    }
    ans=max(ans, d1+d2);
    return dist;
}

int main()
{
    cin>>n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b, c;
        cin>>a>>b>>c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);
    cout<<ans<<endl;
    return 0;
}
```



## 皇宫看守

```c++
/*
太平王世子事件后，陆小凤成了皇上特聘的御前一品侍卫。

皇宫各个宫殿的分布，呈一棵树的形状，宫殿可视为树中结点，两个宫殿之间如果存在道路直接相连，则该道路视为树中的一条边。

已知，在一个宫殿镇守的守卫不仅能够观察到本宫殿的状况，还能观察到与该宫殿直接存在道路相连的其他宫殿的状况。

大内保卫森严，三步一岗，五步一哨，每个宫殿都要有人全天候看守，在不同的宫殿安排看守所需的费用不同。

可是陆小凤手上的经费不足，无论如何也没法在每个宫殿都安置留守侍卫。

帮助陆小凤布置侍卫，在看守全部宫殿的前提下，使得花费的经费最少。

输入格式
输入中数据描述一棵树，描述如下：

第一行 n，表示树中结点的数目。

第二行至第 n+1 行，每行描述每个宫殿结点信息，依次为：该宫殿结点标号 i，在该宫殿安置侍卫所需的经费 k，该结点的子结点数 m，接下来 m 个数，分别是这个结点的 m 个子结点的标号 r1,r2,…,rm。

对于一个 n 个结点的树，结点标号在 1 到 n 之间，且标号不重复。

输出格式
输出一个整数，表示最少的经费。

数据范围
1≤n≤1500
输入样例：
6
1 30 3 2 3 4
2 16 2 5 6
3 5 0
4 4 0
5 11 0
6 5 0
输出样例：
25
样例解释：
在2、3、4结点安排护卫，可以观察到全部宫殿，所需经费最少，为 16 + 5 + 4 = 25。

难度：中等
时/空限制：1s / 64MB
总通过数：4041
总尝试数：8523
来源：《信息学奥赛一本通》
算法标签
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1510;
int h[N], e[N], ne[N], w[N], idx;
int n, f[N][3];
bool st[N];
void add(int a, int b);
void dfs(int u);
/*
f[i][0] 表示被父节点观察到 
f[i][1] 表示被子节点观察到
f[i][2] 表示被自己观察到
*/
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)
    {
        int id,cost,cnt;
        scanf("%d%d%d",&id,&cost,&cnt);
        w[id] = cost;
        while(cnt--)
        {
            int ver;
            scanf("%d",&ver);
            add(id, ver);
            st[ver] = true;
        }
    }
    
    int root = 1;
    while(st[root])
        ++root;
    
    dfs(root);
    
    printf("%d",min(f[root][1], f[root][2]));
    
    return 0;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    f[u][0] = 0;
    f[u][1] = 1e9;
    f[u][2] = w[u]; 
    for(int i = h[u]; ~i;  i = ne[i])
    {
        int j = e[i];
        
        dfs(j);
        
        f[u][0] += min(f[j][1],f[j][2]);
        f[u][2] += min(min(f[j][0],f[j][1]),f[j][2]);
    }
    for(int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        f[u][1]=min(f[u][1], f[u][0] + f[j][2] - min(f[j][1],f[j][2]));
    }
}
```



# 数位DP

```c++
/*
由于科协里最近真的很流行数字游戏。

某人又命名了一种取模数，这种数字必须满足各位数字之和 mod N 为 0。

现在大家又要玩游戏了，指定一个整数闭区间 [a.b]，问这个区间内有多少个取模数。

输入格式
输入包含多组测试数据，每组数据占一行。

每组数据包含三个整数 a,b,N。

输出格式
对于每个测试数据输出一行结果，表示区间内各位数字和 mod N 为 0 的数的个数。

数据范围
1≤a,b≤231−1,
1≤N<100
输入样例：
1 19 9
输出样例：
2
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=11, M=110;
int f[N][10][M], P;
int mod(int x, int y);
void init();
int dp(int n);

int main()
{
    int l,r;
    while(cin>>l>>r>>P)
    {
        init();
        cout<<dp(r)-dp(l-1)<<endl;
    }
    return 0;
}

int mod(int x, int y)
{
    return (x%y+y)%y;
}

void init()
{
    memset(f,0,sizeof f);
    
    for(int i=0;i<=9;++i)
        ++f[1][i][i%P];
        
    for(int i=2;i<N;++i)
        for(int j=0;j<=9;++j)
            for(int k=0;k<P;++k)
                for(int x=0;x<=9;++x)
                    f[i][j][k] += f[i-1][x][mod(k-j,P)];
}

int dp(int n)
{
    if(!n)
        return 1;
    int res=0, last=0;
    vector<int> nums;
    while(n)
    {
        nums.push_back(n%10);
        n/=10;
    }
    for(int i=nums.size()-1;i>=0;--i)
    {
        int x=nums[i];
        for(int j=0;j<x;++j)
            res += f[i+1][j][mod(-last,P)];
        last += x;
        if(!i && last%P==0)
            ++res;
    }
    return res;
}
```



## 分层图最短路

```c++
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int, int>
const int mod = 1e9+7;
const int maxn = 5e4 * 42;
using namespace std;
struct node {int to,w,next;} edge[maxn];
int head[maxn], cnt;
int dis[maxn], vis[maxn];
int n, m, s, t, k;
struct Dijkstra
{
    void init()
    {
        memset(head,-1,sizeof(head));
        memset(dis,0x3f,sizeof(dis));
        memset(vis,0,sizeof(vis));
        cnt = 0;
    }
 
    void add(int u,int v,int w)
    {
        edge[cnt].to = v;
        edge[cnt].w = w;
        edge[cnt].next = head[u];
        head[u] = cnt ++;
    }
 
    void dijkstra()
    {
        priority_queue<pii,vector<pii>,greater<pii> > q;
        dis[s] = 0; q.push({dis[s],s});
        while(!q.empty())
        {
            int now = q.top().second;
            q.pop();
            if(vis[now]) continue;
            vis[now] = 1;
            for(int i = head[now]; i != -1; i = edge[i].next)
            {
                int v = edge[i].to;
                if(!vis[v] && dis[v] > dis[now] + edge[i].w)
                {
                    dis[v] = dis[now] + edge[i].w;
                    q.push({dis[v],v});
                }
            }
        }
    }
}dj;
 
int main()
{
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        dj.init(); scanf("%d%d",&s,&t);
        while(m--)
        {
            int u, v, w;
            scanf("%d%d%d",&u, &v, &w);
            for(int i = 0; i <= k; i++)
            {
                dj.add(u + i * n, v + i * n, w);
                dj.add(v + i * n, u + i * n, w);
                if(i != k)
                {
                    dj.add(u + i * n, v + (i + 1) * n, 0);
                    dj.add(v + i * n, u + (i + 1) * n, 0);
                }
            }
        }
        dj.dijkstra(); int ans = inf;
        for(int i = 0; i <= k; i++)
            ans = min(ans, dis[t + i * n]);
 
        printf("%d\n",ans);
    }
}
```

