#     动态规划(DP)



[TOC]



## 背包问题



### 01背包问题

<img src="D:\桌面\算法\算法笔记\01背包问题.png" style="zoom: 50%;" />
$$
\begin{align}
&对于上面的朴素DP做法而言: 对于物品仅有选与不选两种情况，如果采用这种暴力枚举的方式，将会得到O(2^n)的\\
&复杂度，这是很糟糕的，那么利用DP的思想，我们另f[i][j]表示从前i个物品中选，且总体积不超过j的合法集合中\\
&价值最大的集合，那么对于第i件物品的选择也仅有选与不选两种策略，当不选择第i件物品，那么此时状态为f[i-1][j]\\
&当选择第i件物品时，由于直接f[i][j]得不到当前集合的最大价值，所以我们需要利用从前i-1件物品中选择体积不超过\\
&j-v[i]时的状态，此时该状态已保证背包中是最大价值，那么仅需要再选择第i件物品即可所以选完第i件物品的状态为\\
&f[i-1][j-v[i]]+w[i].那么我们可以得到f[i][j]的状态应为max(f[i-1][j],f[i-1][j-v[i]]+w[i]).此时可得到朴素\\
&DP的解法.\\
\\
&得到最朴素的DP解法的状态转移方程时，对其分析可以发现，我们对于f[i][j]状态的获得仅需要利用f[i-1][]时的状\\
&态，即没有选取i时的状态，其中一个是没有选取i的前提下体积不超过j的状态(此时价值最大)，另一个是(考虑选取i)\\
&但是需要通过没有选取i并且背包中预留足够放置i的空间时的状态，而这两个状态都仅与f[i-1][]有关，那么由此我\\
&们可以使用滚动窗口来优化空间复杂度，仅需开一维数组.(计算f[i][j]时用到两个状态理解如下图)，由此，可以省\\
&去第一维，由此得到新的状态转移方程为f[j]=max(f[j],f[j-v[i]]+w[i])，但与此同时会出现一个问题，每一次\\
&需要使用f[j]和f[j-v[i]]两个状态是上一次运算保留在数组中的，倘若内循环仍然正序遍历，那么在计算下一个新\\
&的状态时，使用的是已经被更新的状态.所以需要将内循环倒叙遍历.
\end{align}
$$
<img src="D:\桌面\算法\算法笔记\01背包滚动数组优化.png" style="zoom: 50%;" />

```c++
/*
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
8
*/
#include <iostream>
using namespace std;
const int N=1010;
int f[N];
int n,m;
int v[N],w[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=m;j>=v[i];--j)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int f[N][N];
int n,m;
int v[N],w[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i]>>w[i];
    }
    
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])
                f[i][j]=max(f[i-1][j],f[i-1][j-v[i]]+w[i]);
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
*/
```



### 完全背包问题

<img src="D:\桌面\算法\算法笔记\完全背包.png" style="zoom: 50%;" />

<img src="D:\桌面\算法\算法笔记\完全背包优化推导.png" style="zoom: 50%;" />
$$
\begin{align}
&针对完全背包问题，我们让f[i][j]表示前i类物品且总体积不大于j的所有集合中价值最大的集合，考虑第i类物品\\
&是否选取，若不选取，则此时状态为f[i-1][j]，若选取，则考虑选取几个，假设选取k个，那么需要利用未选取第\\
&i类物品(k个都没选)时的状态，即为:f[i-1][j-k*v[i]]，那么此时再选取k件i类物品得到的状态就可以得到为:\\
&f[i-1][j-k*v[i]]+k*w[i]，观察两个式子可以发现可将两个式子合并，不选第i类物品时即为k=0时的状态.\\
&需要表示的f[i][j]=max(f[i-1][j-k*v[i]]+k*w[i])(0\leq k\leq n)，此时便已得到朴素的DP做法.当然我们仍\\
&可以对其进行优化.对于这里的第一次优化看了较多的解释，此处仅给出自己理解的解释.由于完全背包对物品数量\\
&没有限制，此处限制为背包的容量，我们先计算并观察一个状态f[i][j-v[i]]，可以发现他和状态f[i][j]的关系，上下\\
&仅相差w[i](如上图)，但在完全背包中最后一项f[i-1][j-kv]此时因为有背包容积的限制,所以再不计w[]的差值时\\
&上下两式最后一项皆为f[i-1][j-k*v[i]]，倘若再有新的f[i-1][j-k*v[i]-v[i]]此时背包已装不下，那么此处\\
&可以证明上图中所表示的关系的正确.由此我们也得到第一次优化，不需要在关心第i类物品去了k件，仅需关心两项\\
&f[i][j]=max(f[i-1][j],f[i][j-v[i]]+w[i]).由此可省去一重循环，之后我们再观察其第一维发现，其与01背包\\
&相似再更新f[i][j]状态的时候仅用到f[i-1][]和f[i][]状态(如下图),那么我们也可以使用滑动数组，与01背包不同的\\
&仅有此处我们不需要将内循环倒叙遍历.当我们更新f[i][j]时需要用到的两个状态不会被更新掉，所以不需要进行\\
&倒叙遍历.则我们可以省去第一维.得到新的状态转移方程为:f[j]=max(f[j],f[j-v[i]]+w[i]).
\end{align}
$$
<img src="D:\桌面\算法\算法笔记\完全背包优化图示.png" style="zoom:50%;" />

```c++
/*
有 N 种物品和一个容量是 V 的背包，每种物品都有无限件可用。
第 i 种物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 种物品的体积和价值。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
10
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int n,m;
int f[N];
int v[N],w[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=v[i];j<=m;++j)
        {
                f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int f[N][N];
int n,m;
int v[N],w[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            f[i][j]=f[i-1][j];
            if(j>=v[i])
            {
                f[i][j]=max(f[i][j],f[i][j-v[i]]+w[i]);
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
*/
/*
//朴素做法超时
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int f[N][N];
int n,m;
int v[N],w[N];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>v[i]>>w[i];
    }
    
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            for(int k=0;k*v[i]<=j;++k)
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    
    cout<<f[n][m]<<endl;
    return 0;
}
*/
```



### 多重背包问题

<img src="D:\桌面\算法\算法笔记\多重背包.png" style="zoom:50%;" />

<img src="D:\桌面\算法\算法笔记\多重背包优化问题.png" style="zoom:50%;" />
$$
\begin{align}
&对于多重背包问题:我们将f[i][j]状态表示为所有只考虑前i类物品，且总体积不大于j的所有选法中价值最大的.\\
&对于第i类物品同时有选不不选的问题，当不选第i类物品时，状态为f[i-1][j]，当选第i类物品时，则需要考虑\\
&选取的数量，则得到状态为:f[i-1][j-k*v[i]]+k*w[i].那么最终f[i][j]=max(f[i-1][j-k*v[i]]+k*w[i])\\
&其中(0 \leq k \leq n)，则此时得到多重背包的朴素DP解法.此时我们可能会考虑对多重背包的朴素做法做优化，可能\\
&会考虑类似完全背包的优化方法，因为此时的多重背包的状态转移方程与完全背包一致，而枚举出结果如上图所示\\
&由于在完全背包中，对物品数量没有限制，有限制的时背包的容积，但是在多重背包中对商品的数量有限制.所以当\\
&多重背包到达状态 f[i-1][j-s[i]*v[i]]+(s[i]-1)*w[i]的时候背包可能并没有满，因此可能再放入物品.那么\\
&这种优化方式也不可取，此时我们对每一类物品进行优化，将每一类物品根据二进制分组，举一个例子当第i类物品\\
&有1023件时，我们可以将其分为1，2，4，8，16……512这样的10组，我们可以通过这10组每一组仅能选择一次，\\
&不同的组合方式可以表示出[1,1023]中任意一个数字，即可以表示取任意的件数，那么此时我们可以将每一类物品\\
&内部转换成01背包问题，因为一类物品内部分组，而每一组仅有两种情况，选与不选，这种优化方式便称为二进制\\
&优化，倘若当某一类商品的个数不能分组成全为2的次方数，那么仅需分组为两大种:一种为可表示到小于该类物品\\
&件数的最大值，一种为商品总件数减去可表示最大值的数量.例如:一类商品有200件，表示方式为:1，2，4，8，16，\\
&32，64，73.当我们分组至64时共有七组，已经可以表示[1,127]的所有数字，倘若再分一组128则会发生矛盾他所表\\
&示的范围会变成[1,255]此时与200件相矛盾，所以最后一组应为73件.那么由此我们可以得到一般情况的分组方式，\\
&假定第i类物品有s件，那么可将其分组为2^0，2^1，2^2……2^k，c.此处的2^k应保证前面所有组合表示数的范围小于\\
&等于该类物品总件数，而c<2^{k+1}. 
\end{align}
$$


```c++
/*
//朴素做法，数据范围较小
有 N 种物品和一个容量是 V 的背包。
第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤100
0<vi,wi,si≤100
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=110;
int f[N][N],s[N],v[N],w[N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>v[i]>>w[i]>>s[i];
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            for(int k=0;k<=s[i]&&k*v[i]<=j;++k)
            {
                f[i][j]=max(f[i][j],f[i-1][j-k*v[i]]+k*w[i]);
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
```

```c++
/*
有 N 种物品和一个容量是 V 的背包。
第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000
提示：
本题考查多重背包的二进制优化方法。
输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=25000,M=2010;
int v[N],w[N];
int f[M];
int n,m;

int main()
{
    cin>>n>>m;
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        int a,b,s;
        cin>>a>>b>>s;
        int k=1;
        while(k<=s)
        {
            ++cnt;
            v[cnt]=a*k;
            w[cnt]=b*k;
            s-=k;
            k*=2;
        }
        if(s>0)
        {
            ++cnt;
            v[cnt]=a*s;  
            w[cnt]=b*s;
        }
    }
    
    n=cnt;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=m;j>=v[i];--j)
        {
            f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
    }
    
    cout<<f[m]<<endl;
    
    return 0;
}
```

$$
\begin{align}
&在前面介绍的多重背包问题的优化方案中我们提供了二进制优化，那么在这里我们在介绍一种多重背包的优化:单调队列优化.\\
&观察下图得推到，并且我们结合多重背包的二维状态表示f[i][j]表示前i个物品中选，且体积不超过j，我们通过下图中可以发现\\
&我们从f[i][r]开始一直到f[i][j]去寻找最值，仅需要做一次滑动窗口即可，所以我们不用去枚举背包可能的体积，仅需要枚举j\%v\\
&的余数即可，当枚举j\%v的余数时，我们每次增加一个v，再<=m的条件下进行滑动窗口即可得到f[i][r]到f[i][j]的最值。
\end{align}
$$

![](D:\桌面\算法\算法笔记\完全背包单调队列优化.png)

```c++
/*
有 N 种物品和一个容量是 V 的背包。
第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V (0<N≤1000, 0<V≤20000)，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N≤1000
0<V≤20000
0<vi,wi,si≤20000
提示
本题考查多重背包的单调队列优化方法。

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=20010;
int n,m;
int f[N],g[N],q[N];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        int v,w,s;
        cin>>v>>w>>s;
        memcpy(g,f,sizeof f);
        for(int j=0;j<v;++j)
        {
            int hh=0,tt=-1;
            for(int k=j;k<=m;k+=v)
            {
                if(hh<=tt&&q[hh] < k-s*v)
                    ++hh;
                if(hh<=tt)
                    f[k]=max(f[k],g[q[hh]]+(k-q[hh])/v*w);
                while(hh<=tt&&g[q[tt]]-(q[tt]-j)/v*w<=g[k]-(k-j)/v*w)
                    --tt;
                q[++tt]=k;
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
```



### 分组背包问题

<img src="D:\桌面\算法\算法笔记\分组背包.png" style="zoom:50%;" />
$$
\begin{align}
&针对分组背包问题:我们另f[i][j]表示从前i组物品中选，且体积不大于j的所有选法中价值最大.对于每一组物品只能\\
&选择该组中的一件物品，所以在考虑f[i][j]状态时，我们需要考虑是否选择第i组物品，若不选择则f[i][j]=f[i-1][j]\\
&若选择则需考虑选择该组中的哪一件，而此时状态为f[i][j]=f[i-1][j-v[i][k]]+w[i][k].从而我们可以得到状态转移\\
&方程为f[i][j]=max(f[i-1][j],f[i-1][j-v[i][k]]+w[i][k]).此处暂不考虑优化，后期会补上优化方法.
\end{align}
$$

```c++
/*
有 N 组物品和一个容量是 V 的背包。
每组物品有若干个，同一组内的物品最多只能选一个。
每件物品的体积是 vij，价值是 wij，其中 i 是组号，j 是组内编号。
求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行有两个整数 N，V，用空格隔开，分别表示物品组数和背包容量。
接下来有 N 组数据：
每组数据第一行有一个整数 Si，表示第 i 个物品组的物品数量；
每组数据接下来有 Si 行，每行有两个整数 vij,wij，用空格隔开，分别表示第 i 个物品组的第 j 个物品的体积和价值；
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤100
0<Si≤100
0<vij,wij≤100
输入样例
3 5
2
1 2
2 4
1
3 4
1
4 5
输出样例：
8
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=110;
int v[N][N],w[N][N],s[N];
int f[N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        for(int j=0;j<s[i];++j)
        {
            cin>>v[i][j]>>w[i][j];
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=m;j>=0;--j)
        {
            for(int k=0;k<s[i];++k)
            {
                if(j>=v[i][k])
                {
                    f[j]=max(f[j],f[j-v[i][k]]+w[i][k]);
                }
            }
        }
    }
    cout<<f[m]<<endl;
    return 0;
}
```

$$
\begin{align}
&这道题目是分组背包的拓展，此处暂时不给予具体讲解，在代码种提供了基本思路，具体解法会在后续第二次复习时给出
\end{align}
$$

```c++
/*
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间金明自己专用的很宽敞的房间。
更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过N元钱就行”。
今天一早，金明就开始做预算了，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：
主件    附件
电脑    打印机，扫描仪
书柜    图书
书桌    台灯，文具
工作椅  无
如果要买归类为附件的物品，必须先买该附件所属的主件。
每个主件可以有0个、1个或2个附件。
附件不再有从属于自己的附件。
金明想买的东西很多，肯定会超过妈妈限定的N元。
于是，他把每件物品规定了一个重要度，分为5等：用整数1~5表示，第5等最重要。
他还从因特网上查到了每件物品的价格（都是10元的整数倍）。
他希望在不超过N元（可以等于N元）的前提下，使每件物品的价格与重要度的乘积的总和最大。
设第j件物品的价格为v[j]，重要度为w[j]，共选中了k件物品，编号依次为j1，j2，…，jk，则所求的总和为：
v[j1]∗w[j1]+v[j2]∗w[j2]+…+v[jk]∗w[jk]（其中*为乘号）
请你帮助金明设计一个满足要求的购物单。
输入格式
输入文件的第1行，为两个正整数，用一个空格隔开：N m，其中N表示总钱数，m为希望购买物品的个数。
从第2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有3个非负整数v p q，其中v表示该物品的价格，p表示该物品的重要度（1~5），q表示该物品是主件还是附件。
如果q=0，表示该物品为主件，如果q>0，表示该物品为附件，q是所属主件的编号。
输出格式
输出文件只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<200000）。
数据范围
N<32000,m<60,v<10000
输入样例：
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
输出样例：
2200
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define v first
#define w second
using namespace std;
typedef pair<int, int> PII;
const int N=70,M=32010;
int n,m;
PII master[N];//存放主件信息
vector<PII> adjunct[N];//存放附件信息
int f[M];//用于状态转换

int main()
{
    cin>>n>>m;
    //存储所有信息
    for(int i=1;i<=m;++i)
    {
        int v,p,q;
        cin>>v>>p>>q;
        if(!q)
            master[i]={v,p*v};
        else
            adjunct[q].push_back({v,p*v});
    }
    
    for(int i=1;i<=m;++i)
    {
        for(int j=n;j>=0;--j)
        {
            for(int k=0;k<(1<<adjunct[i].size());++k)
            {
                //枚举当前主件购买，之后才可以购买与该主件匹配的附件
                int v=master[i].v;
                int w=master[i].w;
                //二进制枚举，由于主件是必买的，所以枚举附件即可，那么使用二进制去判断
                //每一个附件是否需要购买，实现状态转移
                for(int u=0;u<adjunct[i].size();++u)
                {
                    //此处k二进制枚举的是附件的购买情况，包含2^(附件个数)种情况
                    if( k >> u & 1 )
                    {
                        v+=adjunct[i][u].v;
                        w+=adjunct[i][u].w;
                    }
                }
                //枚举完一种情况后判断是否需要更新最大值
                //当剩余金额大于当前购买的消费时才去判断是否更新
                if(j>=v)
                    f[j]=max(f[j],f[j-v]+w);
            }
        }
    }
    
    cout<<f[n]<<endl;
    
    return 0;
}
```

### 混合背包

$$
\begin{align}
&混合背包问题
\end{align}
$$

```c++
/*
有 N 种物品和一个容量是 V 的背包。
物品一共有三类：
第一类物品只能用1次（01背包）；
第二类物品可以用无限次（完全背包）；
第三类物品最多只能用 si 次（多重背包）；
每种体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。
接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。
si=−1 表示第 i 种物品只能用1次；
si=0 表示第 i 种物品可以用无限次；
si>0 表示第 i 种物品可以使用 si 次；
输出格式
输出一个整数，表示最大价值。
数据范围
0<N,V≤1000
0<vi,wi≤1000
−1≤si≤1000
输入样例
4 5
1 2 -1
2 4 1
3 4 0
4 5 2
输出样例：
8
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int v[N],w[N],s[N];
int n,m;
int f[N];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>v[i]>>w[i]>>s[i];
    
    for(int i=0;i<n;++i)
    {
        if(!s[i])//完全背包
        {
            for(int j=v[i];j<=m;++j)
                f[j]=max(f[j],f[j-v[i]]+w[i]);
        }
        else
        {
            if(s[i]==-1)
                s[i]=1;
            
            for(int k=1;k<=s[i];k*=2)
            {
                for(int j=m;j>=k*v[i];--j)
                {
                    f[j]=max(f[j],f[j-k*v[i]]+k*w[i]);
                }
                s[i]-=k;
            }
        
            if(s[i])
            {
                for(int j=m;j>=s[i]*v[i];--j)
                {
                    f[j]=max(f[j],f[j-s[i]*v[i]]+s[i]*w[i]);
                }
            }
        }
    }
    
    cout<<f[m]<<endl;
    
    return 0;
}
```



### 二维费用背包问题

$$
\begin{align}
&二维费用背包问题
\end{align}
$$

```c++
/*
有 N 件物品和一个容量是 V 的背包，背包能承受的最大重量是 M。
每件物品只能用一次。体积是 vi，重量是 mi，价值是 wi。
求解将哪些物品装入背包，可使物品总体积不超过背包容量，总重量不超过背包可承受的最大重量，且价值总和最大。
输出最大价值。
输入格式
第一行三个整数，N,V,M，用空格隔开，分别表示物品件数、背包容积和背包可承受的最大重量。
接下来有 N 行，每行三个整数 vi,mi,wi，用空格隔开，分别表示第 i 件物品的体积、重量和价值。
输出格式
输出一个整数，表示最大价值。
数据范围
0<N≤1000
0<V,M≤100
0<vi,mi≤100
0<wi≤1000
输入样例
4 5 6
1 2 3
2 4 4
3 4 5
4 5 6
输出样例：
8
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int f[N][N],v[N],m[N],w[N];
int n,V,M;

int main()
{
    cin>>n>>V>>M;
    for(int i=1;i<=n;++i)
        cin>>v[i]>>m[i]>>w[i];
    
    for(int i=1;i<=n;++i)
    {
        for(int j=V;j>=v[i];--j)
        {
            for(int k=M;k>=m[i];--k)
            {
                f[j][k]=max(f[j][k],f[j-v[i]][k-m[i]]+w[i]);
            }
        }
    }
    
    cout<<f[V][M]<<endl;
    return 0;
}
```

### 有依赖的背包问题

$$
\begin{align}
&有依赖的背包问题
\end{align}
$$

```c++
/*
有 N 个物品和一个容量是 V 的背包。
物品之间具有依赖关系，且依赖关系组成一棵树的形状。如果选择一个物品，则必须选择它的父节点。
如下图所示：
如果选择物品5，则必须选择物品1和2。这是因为2是5的父节点，1是2的父节点。
每件物品的编号是 i，体积是 vi，价值是 wi，依赖的父节点编号是 pi。物品的下标范围是 1…N。
求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
输出最大价值。
输入格式
第一行有两个整数 N，V，用空格隔开，分别表示物品个数和背包容量。
接下来有 N 行数据，每行数据表示一个物品。
第 i 行有三个整数 vi,wi,pi，用空格隔开，分别表示物品的体积、价值和依赖的物品编号。
如果 pi=−1，表示根节点。 数据保证所有物品构成一棵树。
输出格式
输出一个整数，表示最大价值。
数据范围
1≤N,V≤100
1≤vi,wi≤100
父节点编号范围：

内部结点：1≤pi≤N;
根节点 pi=−1;
输入样例
5 7
2 3 -1
2 2 1
3 5 1
4 7 2
3 6 2
输出样例：
11
*/
#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;
const int N=110;
int n,m;
int h[N],e[N],ne[N],idx;
int v[N],w[N];
int f[N][N];
void add(int a,int b);
void dfs(int u);

int main()
{
    cin>>n>>m;
    memset(h,-1,sizeof h);
    int root;
    for(int i=1;i<=n;++i)
    {
        int p;
        cin>>v[i]>>w[i]>>p;
        if(p==-1)
            root=i;
        else
            add(p,i);
    }
    
    dfs(root);
    
    cout<<f[root][m]<<endl;
        
    return 0;
}
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
/*
void dfs(int u)
{
    for(int i=h[u];~i;i=ne[i])
    {
        int son=e[i];
        dfs(son);
        for(int j=m-v[u];j>=0;--j)
        {
            for(int k=0;k<=j;++k)
            {
                f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);
            }
        }
    }
    
    for(int j=m;j>=v[u];--j)
        f[u][j]=f[u][j-v[u]]+w[u];
    for(int j=0;j<v[u];++j)
        f[u][j]=0;
    
}
*/
void dfs(int u)
{
    for(int i=v[u];i<=m;++i)
        f[u][i]=w[u];
    for(int i=h[u];~i;i=ne[i])
    {
        int son=e[i];
        dfs(son);
        for(int j=m;j>=v[u];--j)
        {
            for(int k=0;k<=j-v[u];++k)
            {
                f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);
            }
        }
    }
}
```

![](D:\桌面\算法\算法笔记\有依赖的背包问题.png)

### 背包问题求解方案数

$$
\begin{align}
&背包问题求解方案数
\end{align}
$$

```c++
/*
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出 最优选法的方案数。注意答案可能很大，请输出答案模 109+7 的结果。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一个整数，表示 方案数 模 109+7 的结果。
数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 6
输出样例：
2
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1010,mod=1e9+7;
int f[N],g[N];
int n,m;

int main()
{
    cin>>n>>m;
    g[0]=1;
    for(int i=0;i<n;++i)
    {
        int v,w;
        cin>>v>>w;
        for(int j=m;j>=v;--j)
        {
            int maxv=max(f[j],f[j-v]+w);
            int cnt=0;
            if(maxv==f[j])
                cnt+=g[j];
            if(maxv==f[j-v]+w)
                cnt+=g[j-v];
            g[j]=cnt%mod;
            f[j]=maxv;
        }
    }
    int res=0;
    for(int i=0;i<=m;++i)
    {
        if(f[i]==f[m])
            res=(res+g[i])%mod;
    }
    cout<<res<<endl;
    return 0;
}
```

### 背包问题求具体方案

$$
\begin{align}
&背包问题求具体方案
\end{align}
$$

```c++
/*
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。
第 i 件物品的体积是 vi，价值是 wi。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出 字典序最小的方案。这里的字典序是指：所选物品的编号所构成的序列。物品的编号范围是 1…N。
输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。
输出格式
输出一行，包含若干个用空格隔开的整数，表示最优解中所选物品的编号序列，且该编号序列的字典序最小。
物品编号范围是 1…N。
数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 6
输出样例：
1 4
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010;
int v[N],w[N],f[N][N];
int n,m;

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>v[i]>>w[i];
    
    for(int i=n;i>=1;--i)
    {
        for(int j=0;j<=m;++j)
        {
            f[i][j]=f[i+1][j];
            if(j>=v[i])
                f[i][j]=max(f[i][j],f[i+1][j-v[i]]+w[i]);
        }
    }
    int j=m;
    for(int i=1;i<=n;++i)
    {
        if(j>=v[i] && f[i][j]==f[i+1][j-v[i]]+w[i])
        {
            cout<<i<<' ';
            j-=v[i];
        }
    }
    return 0;
}
```



## 线性DP

$$
\begin{align}
&针对线性DP问题大多数问题没有固定的模板，仅能对实际问题进行分析，从而去寻找状态转移方程，而\\
&之所以将其归纳为线性DP是因为其解决过程是类似线一般，并且状态间有线性关系(可能并不是很明显).
\end{align}
$$

### 数字三角形问题

$$
\begin{align}
&针对第一题\quad数字三角形：\\
&我们需要求解出一条路径，使得该条路径上的数字之和最大.\\
&此处如下图分析
\end{align}
$$

<img src="D:\桌面\算法\算法笔记\数字三角形（数塔）问题分析.png" style="zoom: 80%;" />
$$
\begin{align}
&上方给出第一种分析方法，我们由上至下分析，将所有状态分析出来，并得到状态转移方程，之后将所有路径\\
&得到的状态总和记录在最后一层，之后仅需比较最后一层的大小找出最大值即可.\\
&接下来再给出第二种分析方法，此处我们由下至上分析，每一个状态取决于他左下和右下两个状态，当左下时:\\
&f[i][j]=f[i+1][j]+f[i][j]，当右下时:f[i][j]=f[i+1][j+1]+f[i][j].由于此时我们由下往上更新时我们需\\
&要使用已经更新出来的状态，所以直接+f[i][j]即可，不需要像由上至下计算时保存数字三角形中的值，当由下\\
&至上计算完之后，最顶端的点即为路径数字和最大的值.状态转移方程为:\\
&f[i][j]=max(f[i+1][j]+f[i][j],f[i+1][j+1]+f[i][j]).\\
\end{align}
$$


```c++
/*
//此处为由下至上的计算.
给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
输入格式
第一行包含整数 n，表示数字三角形的层数。
接下来 n 行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。
输出格式
输出一个整数，表示最大的路径数字和。
数据范围
1≤n≤500,
−10000≤三角形中的整数≤10000
输入样例：
5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5
输出样例：
30
*/
#include <iostream>
using namespace std;
const int N=510;
int f[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            cin>>f[i][j];
        }
    }

    for(int i=n-1;i>=1;--i)
    {
        for(int j=1;j<=i;++j)
        {
            f[i][j]=max(f[i+1][j]+f[i][j],f[i+1][j+1]+f[i][j]);
        }
    }
    
    cout<<f[1][1]<<endl;
    return 0;
}
```

### 最长上升子序列问题

$$
\begin{align}
&针对最长上升子序列问题分析如下图.\\
&注意：子序列可以不连续，但需要保证在原字符串中顺序一致.而子串是连续的并且和原字符串一致.
\end{align}
$$

<img src="D:\桌面\算法\算法笔记\最长上升子序列问题分析.png" style="zoom:80%;" />
$$
\begin{align}
&此处我们需要每次更新的状态时f[i](以i结尾的最长上升子序列的最大值)，那么我们需要分析的是他前面数字的\\
&状态，我们观察他前面数字的状态，发现可将它前面的数字分为i类，0代表前面已经没有数字了，f[0]=0,我们\\
&需要找到f[j](0<=j<=i-1)<f[i]的那一类，在他的基础上我们可以将以i结尾的最长上升子序列的状态更新\\
&为f[i]=f[j]+1,但是由于满足条件的j不唯一，所以我们需要将所有满足条件的取最大值才满足属性，由此得到\\
&状态转移方程为f[i]=max(f[j]+1).
\end{align}
$$

```c++
/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。
输入格式
第一行包含整数 N。
第二行包含 N 个整数，表示完整序列。
输出格式
输出一个整数，表示最大长度。
数据范围
1≤N≤1000，
−109≤数列中的数≤109
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/
#include <iostream>
using namespace std;
const int N=1010;
int a[N],f[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;++i)
    {
        f[i]=1;
        for(int j=1;j<i;++j)
        {
            if(a[j]<a[i])
            {
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    int res=0;
    for(int i=1;i<=n;++i)
    {
        if(res<f[i])
            res=f[i];
    }
    
    cout<<res<<endl;
    
    return 0;
}

/*
//输出最长上升子序列的路径
#include <iostream>
using namespace std;
const int N=1010;
int a[N],f[N],g[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    
    for(int i=1;i<=n;++i)
    {
        f[i]=1;
        g[i]=0;
        for(int j=1;j<i;++j)
        {
            if(a[j]<a[i])
            {
                if(f[i]<f[j]+1)
                {
                    f[i]=f[j]+1;
                    g[i]=j;
                }
            }
        }
    }
    
    int k=1;
    for(int i=1;i<=n;++i)
    {
        if(f[i]>f[k])
        {
            k=i;
        }
    }
    
    cout<<f[k]<<endl;
    for(int i=0,len=f[k];i<len;++i)
    {
        cout<<a[k]<<" ";
        k=g[k];
    }
    return 0;
}
*/
```

$$
\begin{align}
&对于最长上升子序列的优化:
\end{align}
$$



```c++
/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。
输入格式
第一行包含整数 N。
第二行包含 N 个整数，表示完整序列。
输出格式
输出一个整数，表示最大长度。
数据范围
1≤N≤100000，
−109≤数列中的数≤109
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/

```



### 最长公共子序列

$$
\begin{align}
&针对最长公共子序列问题的分析如下图\\
&对于状态表示我们将其分为四种情况来观察，第一种是不包含a[i]和b[j]的最长公共子序列，第四种是包含a[i]和b[j]的最长\\
&公共子序列,但第二种以及第三种，一种是不包含a[i]，包含b[j]，一种是包含a[i]不包含b[j]，或许会很容易想到用图中两个\\
&方式来表达，但是从状态表示的定义来阐述两个表达式的含义，f[i-1][j]表达的是由第一个序列前i-1个字母，和第二个\\
&序列前j个字母构成的公共序列，仅能说明最长公共子序列的结尾在前j个字母中出现，但不一定是b[j]，同理f[i][j-1]也是\\
&这样的情况，但是由于这两个表达式包含了这两种情况，所以当求其最大值时并不影响结果.并且f[i-1][j]同时也包含了第\\
&一种情况.所以由此我们可以根据三种情况分析出状态转移方程为:\\
&f[i][j]=max(f[i-1][j],f[i][j-1],f[i-1][j-1]+1).
\end{align}
$$



<img src="D:\桌面\算法\算法笔记\最长公共子序列问题状态分析.png" style="zoom: 80%;" />

```c++
/*
给定两个长度分别为 N 和 M 的字符串 A 和 B，求既是 A 的子序列又是 B 的子序列的字符串长度最长是多少。
输入格式
第一行包含两个整数 N 和 M。
第二行包含一个长度为 N 的字符串，表示字符串 A。
第三行包含一个长度为 M 的字符串，表示字符串 B。
字符串均由小写字母构成。
输出格式
输出一个整数，表示最大长度。
数据范围
1≤N,M≤1000
输入样例：
4 5
acbd
abedc
输出样例：
3
*/
#include <iostream>
using namespace std;
const int N=1010;
char a[N],b[N];
int f[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    cin>>a+1>>b+1;
    
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            f[i][j]=max(f[i-1][j],f[i][j-1]);
            if(a[i]==b[j])
            {
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            }
        }
    }
    cout<<f[n][m]<<endl;
    return 0;
}
```

### 最长上升序列Ⅱ

$$
\begin{align}
&对于上方的最长上升序列问题数据范围仅有1000，所以O(n^2)的时间复杂度可以过，但是在这道题目中数据范围是1e5，O(n^2)的复杂度是过不了的，\\
&那么该如何优化呢，其实这里用到的算法应该不属于动态规划了，但是为了和上面的题形成对比，所以将这道题写在了这里，此处直接给出算法由于比\\
&较难思考到，我们可以利用贪心和二分的解法，我们开两个数组a[N]，q[N]，其中a[N]用来存储序列，而q[N]用于存储以不同数字结尾的序列，每一\\
&个元素q[i]表示以q[i]结尾的长度为i的最长上升序列，我们不难想到每一次去寻找上升序列的时候以较小数字会比较好，因为后面会更容易接上大的数字\\
&从而构成上升序列，而数组q[N]必然是单调递增的，由于长度越小的上升序列我们保证以较小的数字结尾，当出现比其长度更大的序列时必然最后一个\\
&是大于长度较小的序列的最后一个元素的。从而保证了数组q[N]的单调性，我们每一次遍历原序列再去寻找上升序列结尾时可以二分的去寻找序列结尾\\
&我们遍历原序列中的一个数字时可以去数组q[N]中寻找小于a[i]的最大的数，而此时就可以得到一个新的上升序列以a[i]结尾长度+1的新的上升序列\\
&在过程中假设第一次的数组a[N]中的第一个数较大，那么q[1]会存储该数字表示以该数字结尾且长度为1的上升序列，假设a[N]的第二个数字比他小，\\
&那么将会把q[1]的元素覆盖保证q[N]的元素单调并且以数字结尾的上升序列必然该数字能取到最小的情况.
\end{align}
$$

```c++
/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。
输入格式
第一行包含整数 N。
第二行包含 N 个整数，表示完整序列。
输出格式
输出一个整数，表示最大长度。
数据范围
1≤N≤100000，
−109≤数列中的数≤109
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e5+10;
int a[N],q[N];
int n;

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];//原序列
    }
    int len=0;//q数组最终不包含q[0]的长度为结果
    q[0]=-2e9;
    //q数组存储的每一位元素q[i]表示以q[i]为结尾且长度为i的最长上升子序列
    for(int i=0;i<n;++i)
    {
        int l=0,r=len;
        while(l<r)
        {
            int mid=l+r+1>>1;
            if(q[mid]<a[i])
                l=mid;
            else
                r=mid-1;
        }
        len=max(len,r+1);
        q[r+1]=a[i];
    }
    cout<<len<<endl;
    return 0;
}
```



### 最短编辑距离





### 编辑距离





## 区间DP

### 石子合并

$$
\begin{align}
&对于石子合并问题，仅能合并相邻的石子堆，并且要保证消耗最小即合并两堆石子得到质量最小，状态分析如下\\
&我们根据石子合并时最后一步将两堆石合并的所在分界线不同来划分不同的状态，需要计算f[i][j]时的状态仅需要\\
&将最后两端两次合并的代价，再加上最后将全部石子合并的代价即可得到f[i][j]这一状态.注：f[i][k]+f[k+1][j]\\
&并不和最后一次将所有石子合并的代价(s[j]-s[i-1])等价，这两个值会有相同的特殊情况而已.
\end{align}
$$

<img src="D:\桌面\算法\算法笔记\区间DP合并石子问题状态分析.png" style="zoom:80%;" />

```c++
/*
设有 N 堆石子排成一排，其编号为 1，2，3，…，N。
每堆石子有一定的质量，可以用一个整数来描述，现在要将这 N 堆石子合并成为一堆。
每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同。
例如有 4 堆石子分别为 1 3 5 2， 我们可以先合并 1、2 堆，代价为 4，得到 4 5 2， 又合并 1，2 堆，代价为 9，得到 9 2 ，再合并得到 11，总代价为 4+9+11=24；
如果第二步是先合并 2，3 堆，则代价为 7，得到 4 7，最后一次合并代价为 11，总代价为 4+7+11=22。
问题是：找出一种合理的方法，使总的代价最小，输出最小代价。
输入格式
第一行一个数 N 表示石子的堆数 N。
第二行 N 个数，表示每堆石子的质量(均不超过 1000)。
输出格式
输出一个整数，表示最小代价。
数据范围
1≤N≤300
输入样例：
4
1 3 5 2
输出样例：
22
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=330;
int s[N];
int f[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>s[i];
    
    for(int i=1;i<=n;++i)
        s[i]+=s[i-1];
    
    for(int len=2;len<=n;++len)
    {
        for(int i=1;i+len-1<=n;++i)
        {
            int l=i,r=i+len-1;
            f[l][r]=1e8;
            for(int k=l;k<r;++k)
            {
                f[l][r]=min(f[l][r],f[l][k]+f[k+1][r]+s[r]-s[l-1]);
            }
        }
    }
    
    cout<<f[1][n]<<endl;
    
    return 0;
}
```



## 计数类DP

<img src="D:\桌面\算法\算法笔记\计数类DP整数划分.png" style="zoom:80%;" />

![](D:\桌面\算法\算法笔记\计数类DP整数划分解法2.png)
$$
\begin{align}
&针对于这道题目给出两种不同的状态转移方程，第一种是参照完全背包问题考虑而来，而第二种是一种比较难想到的划分方式.\\
&
\end{align}
$$

```c++
/*
一个正整数 n 可以表示成若干个正整数之和，形如：n=n1+n2+…+nk，其中 n1≥n2≥…≥nk,k≥1。
我们将这样的一种表示称为正整数 n 的一种划分。
现在给定一个正整数 n，请你求出 n 共有多少种不同的划分方法。
输入格式
共一行，包含一个整数 n。
输出格式
共一行，包含一个整数，表示总划分数量。
由于答案可能很大，输出结果请对 109+7 取模。
数据范围
1≤n≤1000
输入样例:
5
输出样例：
7
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010,mod=1e9+7;
int f[N][N],n;

int main()
{
    cin>>n;
    f[0][0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=i;++j)
        {
            f[i][j]=(f[i-1][j-1]+f[i-j][j])%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        ans=(ans+f[n][i])%mod;
    }
    cout<<ans<<endl;
    return 0;
}
/*
#include <iostream>
#include <algorithm>
using namespace std;
const int N=1010,mod=1e9+7;
int f[N],n;

int main()
{
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=i;j<=n;++j)
        {
            f[j]=(f[j]+f[j-i])%mod;
        }
    }
    
    cout<<f[n]<<endl;
    
    return 0;
}
*/
```



## 数位统计DP

```c++
/*
给定两个整数 a 和 b，求 a 和 b 之间的所有数字中 0∼9 的出现次数。

例如，a=1024，b=1032，则 a 和 b 之间共有 9 个数如下：

1024 1025 1026 1027 1028 1029 1030 1031 1032

其中 0 出现 10 次，1 出现 10 次，2 出现 7 次，3 出现 3 次等等…

输入格式
输入包含多组测试数据。

每组测试数据占一行，包含两个整数 a 和 b。

当读入一行为 0 0 时，表示输入终止，且该行不作处理。

输出格式
每组数据输出一个结果，每个结果占一行。

每个结果包含十个用空格隔开的数字，第一个数字表示 0 出现的次数，第二个数字表示 1 出现的次数，以此类推。

数据范围
0<a,b<100000000
输入样例：
1 10
44 497
346 542
1199 1748
1496 1403
1004 503
1714 190
1317 854
1976 494
1001 1960
0 0
输出样例：
1 2 1 1 1 1 1 1 1 1
85 185 185 185 190 96 96 96 95 93
40 40 40 93 136 82 40 40 40 40
115 666 215 215 214 205 205 154 105 106
16 113 19 20 114 20 20 19 19 16
107 105 100 101 101 197 200 200 200 200
413 1133 503 503 503 502 502 417 402 412
196 512 186 104 87 93 97 97 142 196
398 1375 398 398 405 499 499 495 488 471
294 1256 296 296 296 296 287 286 286 247
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int get(vector<int> num,int l,int r);
int power10(int x);
int count(int n,int x);

int main()
{
    int a,b;
    while(cin>>a>>b,a||b)
    {
        if(a>b)
            swap(a,b);
        for(int i=0;i<10;++i)
        {
            cout<<count(b,i)-count(a-1,i)<<" ";
        }
        puts("");
    }
    return 0;
}

int get(vector<int> num,int l,int r)
{
    int res=0;
    for(int i=l;i>=r;--i)
        res=res*10+num[i];
    return res;
}

int power10(int x)
{
    int res=1;
    while(x--)
        res*=10;
    return res;
}

int count(int n,int x)
{
    if(!n)
        return 0;
    
    vector<int> num;
    
    while(n)
    {
        num.push_back(n%10);
        n/=10;
    }
    
    n=num.size();
    int res=0;
    for(int i=n-1-!x;i>=0;--i)
    {
        if(i<n-1)
        {
            res+=get(num,n-1,i+1)*power10(i);
            if(!x)    
                res-=power10(i);
        }
        if(num[i]==x)
            res+=(get(num,i-1,0)+1);
        else if(num[i]>x)
            res+=power10(i);
    }
    
    return res;
}
```



## 状态压缩DP

![](动态规划(DP).assets/蒙德里安.png)

```c++
/*
求把 N×M 的棋盘分割成若干个 1×2 的长方形，有多少种方案。

例如当 N=2，M=4 时，共有 5 种方案。当 N=2，M=3 时，共有 3 种方案。

如下图所示：

输入格式
输入包含多组测试用例。

每组测试用例占一行，包含两个整数 N 和 M。

当输入用例 N=0，M=0 时，表示输入终止，且该用例无需处理。

输出格式
每个测试用例输出一个结果，每个结果占一行。

数据范围
1≤N,M≤11
输入样例：
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
输出样例：
1
0
1
2
3
5
144
51205
难度：中等
时/空限制：1.5s / 64MB
总通过数：22023
总尝试数：38767
来源：《算法竞赛进阶指南》, 模板题
算法标签
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long LL;
const int N=12,M=1<<N;
int n,m;
LL f[N][M];
bool st[M];
vector< vector<int> >state(M);

int main()
{
    while(cin>>n>>m,n||m)
    {
        //预处理枚举每一列所有可能状态是否会出现奇数个0
        for(int i=0;i< 1<<n;++i)
        {
            int cnt=0;
            bool flag=true;
            for(int j=0;j<n;++j)
            {
                if(i>>j&1)
                {
                    if(cnt&1)
                    {
                        flag=false;
                        break;
                    }
                    cnt=0;
                }
                else
                    ++cnt;
            }
            if(cnt&1)
            {
                flag=false;
            }
            st[i]=flag;
        }
        
        //预处理枚举所有情况判断会不会发生重叠，将不会发生的存储在state中
        for(int i=0;i< 1<<n;++i)
        {
            state[i].clear();
            for(int j=0;j< 1<<n;++j)
            {
                if(((i&j)==0)&&st[i|j])
                {
                    state[i].push_back(j);
                }
            }
        }
        
        memset(f,0,sizeof f);
        f[0][0]=1;
        for(int i=1;i<=m;++i)
        {
            for(int j=0;j<1<<n;++j)
            {
                for(auto k:state[j])
                {
                    f[i][j]+=f[i-1][k];
                }
            }
        }
        cout<<f[m][0]<<endl;
    }
    return 0;
}
```



## 树形DP

```c++
/*
Ural 大学有 N 名职员，编号为 1∼N。

他们的关系就像一棵以校长为根的树，父节点就是子节点的直接上司。

每个职员有一个快乐指数，用整数 Hi 给出，其中 1≤i≤N。

现在要召开一场周年庆宴会，不过，没有职员愿意和直接上司一起参会。

在满足这个条件的前提下，主办方希望邀请一部分职员参会，使得所有参会职员的快乐指数总和最大，求这个最大值。

输入格式
第一行一个整数 N。

接下来 N 行，第 i 行表示 i 号职员的快乐指数 Hi。

接下来 N−1 行，每行输入一对整数 L,K，表示 K 是 L 的直接上司。

输出格式
输出最大的快乐指数。

数据范围
1≤N≤6000,
−128≤Hi≤127
输入样例：
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
输出样例：
5
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=6010;
int w[N],f[N][2];
int h[N],e[N],ne[N],idx;
bool st[N];
int n;
void add(int a,int b);
void dfs(int root);

int main()
{
    memset(h,-1,sizeof h);
    
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>w[i];
    for(int i=0;i<n-1;++i)
    {
        int a,b;
        cin>>a>>b;
        add(b,a);
        st[a]=true;
    }
    int root=1;
    while(st[root])
        ++root;
    dfs(root);
    
    cout<<max(f[root][0],f[root][1])<<endl;
    
    return 0;
}

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dfs(int root)
{
    f[root][1]=w[root];
    for(int i=h[root];~i;i=ne[i])
    {
        int j=e[i];
        dfs(j);
        f[root][0]+=max(f[j][0],f[j][1]);
        f[root][1]+=f[j][0];
    }
}
```





## 记忆化搜索

```c++
/*
给定一个 R 行 C 列的矩阵，表示一个矩形网格滑雪场。

矩阵中第 i 行第 j 列的点表示滑雪场的第 i 行第 j 列区域的高度。

一个人从滑雪场中的某个区域内出发，每次可以向上下左右任意一个方向滑动一个单位距离。

当然，一个人能够滑动到某相邻区域的前提是该区域的高度低于自己目前所在区域的高度。

下面给出一个矩阵作为例子：

 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9
在给定矩阵中，一条可行的滑行轨迹为 24−17−2−1。

在给定矩阵中，最长的滑行轨迹为 25−24−23−…−3−2−1，沿途共经过 25 个区域。

现在给定你一个二维矩阵表示滑雪场各区域的高度，请你找出在该滑雪场中能够完成的最长滑雪轨迹，并输出其长度(可经过最大区域数)。

输入格式
第一行包含两个整数 R 和 C。

接下来 R 行，每行包含 C 个整数，表示完整的二维矩阵。

输出格式
输出一个整数，表示可完成的最长滑雪长度。

数据范围
1≤R,C≤300,
0≤矩阵中整数≤10000
输入样例：
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出样例：
25
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=310;
int r,c;
int h[N][N],f[N][N];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
int dp(int x,int y);

int main()
{
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            cin>>h[i][j];
        }
    }
    
    memset(f,-1,sizeof f);
    int res=0;
    for(int i=0;i<r;++i)
    {
        for(int j=0;j<c;++j)
        {
            res=max(res,dp(i,j));
        }
    }
     cout<<res<<endl;   
    return 0;
}

int dp(int x,int y)
{
    int &v=f[x][y];
    if(v!=-1)
        return v;
    
    v=1;
    for(int i=0;i<4;++i)
    {
        int a=x+dx[i],b=y+dy[i];
        if(a>=0&&a<r&&b>=0&&b<c&&h[x][y]>h[a][b])
        {
            v=max(v,dp(a,b)+1);
        }
    }
    return v;
}
```



