/*
 * p10
 */

#include <iostream>

using namespace std;
const int MaxSize = 110;
typedef int ElemType;
struct TreeNode
{
    ElemType element;
    TreeNode *leftson, *rightson;
};
struct Queue
{
    int front, rear;
    TreeNode* data[MaxSize];
};
struct Tree
{
    TreeNode *root;
};
void InitQueue(Queue &q);
bool IsEmpty(Queue &q);
bool EnQueue(Queue &q, TreeNode *x);
bool DeQueue(Queue &q, TreeNode *&x);

void Init(Tree &tree);
TreeNode* CreateTree();
int Find_k(TreeNode *&r);
void Porder(TreeNode* r);
int k, id = 1;

int main()
{
    Tree tree;
    puts("��������ڵ�");
    tree.root = CreateTree();
    puts("��������Ҫ��ȡ��������еڼ����ڵ��ֵ");
    cin >> k;
    if (k == -1)
    {
        puts("���нڵ㲻��");
        return 0;
    }
    cout << "ֵΪ��" << Find_k(tree.root) << endl;
    cout << "����";
    Porder(tree.root);
    return 0;
}

void Init(Tree &tree)
{
    tree.root = nullptr;
}

TreeNode* CreateTree()
{
    TreeNode *root = new TreeNode;
    int e;
    cin >> e;
    if (e == -1)
        return NULL;
    else
    {
        root->element = e;
        cout << "������������" << endl;
        root->leftson = CreateTree();
        cout << "������������" << endl;
        root->rightson = CreateTree();
        return root;
    }
}


void InitQueue(Queue &q)
{
    q.front = q.rear = -1;
}

bool IsEmpty(Queue &q)
{
    return q.front == q.rear;
}

bool EnQueue(Queue &q, TreeNode *x)
{
    if (q.rear == MaxSize)
        return false;
    q.data[++ q.rear] = x;
    return true;
}

bool DeQueue(Queue &q, TreeNode *&x)
{
    if (IsEmpty(q))
        return false;
    x = q.data[++ q.front];
    return true;
}

void Porder(TreeNode* r)
{
    if (!r)
        return ;
    cout << r->element << " ";
    Porder(r->leftson);
    Porder(r->rightson);
}
int Find_k(TreeNode *&r)
{
    if (!r)
        return -1;
    if (id == k)
        return r->element;
    ++ id;
    int val = Find_k(r->leftson);
    if (val != -1)
        return val;
    val = Find_k(r->rightson);
    return val;
}
