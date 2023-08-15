/*
 * 顺序存储儿茶素
 */
#include <iostream>
#define MaxSize 100
using namespace std;

typedef int ElemTye;
struct TNode
{
    ElemTye value;
    bool isEmpty;
};

struct SqTree
{
    TNode sqTree[MaxSize];
};

void Init(SqTree &tree);
void CreateTree(SqTree &tree, int i);

int main()
{

    return 0;
}

void Init(SqTree &tree)
{
    for (int i = 0; i < MaxSize; ++ i)
        tree.sqTree[i].isEmpty = true;
}

void CreateTree(SqTree &tree, int i)
{
    char ch;
    cin >> ch;
    tree.sqTree[i] = {ch, false};
    cout << "请输出左子树节点值，若没有左子树请输入#" << endl;
    CreateTree(tree, 2 * i);
    cout << "请输出右子树节点值，若没有左子树请输入#" << endl;
    CreateTree(tree, 2 * i + 1);
}
