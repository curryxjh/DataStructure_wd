# 常用STL



## vector

```C++
#include <vector>
//vector<要存数据的类型> 名字;//定义
//例如
vector<int> a;
vector<int> a(10);//指定大小
a.push_back(10);//存入元素
a.pop_back();//拿出元素，默认拿最后一个元素
a.size();//返回元素个数
reverse(a.begin(), a.end());//倒置整个a
//a.begin()返回首地址, a.end()返回尾地址
a.erase(a.begin());//删除第一个元素 ，参数是你想要删除元素的地址
a.erase(a.begin(), a.end());//删除全部元素，参数是你想要删除元素区间的首尾地址
```

## queue

```C++
#include <queue>
//queue<要存的数据类型> 名字 //定义
queue<int> q;
q.push(10);//压入元素队尾
q.pop();//队首删除元素
q.size();//元素个数2
q.empty();//判断空不空，返回true说明空
```

## stack

```C++
#include <stack>
//stack<要存的数据类型> 名字; //定义
stack<int> a;
a.push(10);//放入元素
a.pop();//拿出元素
a.size();//返回元素个数
a.empty();//判断空不空
```

## set

```C++
#include <set>
//set<要存的数据类型> 名字; //定义
set<int> a;
a.insert(10);//放入元素
a.erase(a.begin());//删除一个元素(头元素),参数是你想要删除元素的地址
a.erase(a.begin(), a.end());//删除一段元素（全部删除）.参数是你想要删除元素区间的首尾地址
a.empty();//判断空不空
```

## map

```C++
#include <map>
//map<要存的数据类型(key)， 要存的数据类型(value)> 名字;//定义
map<string, int> m;
m["abc"]=1;//放元素
m.count("abc");//返回传入参数在你定义的map里面key是否出现过.
//map和unordered_map区别在于，map有序，unordered_map无序,并且unordered_map更快
```

## unordered_map

```C++
#include <unordered_map>
//unordered_map<要存的数据类型(key), 要存的数据类型(value)> 名字;//定义
unordered_map<string, int> m;
m["abc"]=1;//放元素
m.count("abc");//返返回传入参数在你定义的map里面key是否出现过.
```



## unordered_set



## pair

```C++
//pair<要存的数据类型, 要存的数据类型> 名字;//定义
pair<int, int> p;
p.first;//访问第一个
p.second;//访问第二个
```



## deque



## priority_queue