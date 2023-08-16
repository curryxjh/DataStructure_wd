/*
 * p04
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
struct Tree
{
    TreeNode *root;
};
struct Stack
{
    int top;
    TreeNode* data[MaxSize];
};
struct Queue
{
    int front, rear;
    TreeNode* data[MaxSize];
};
void InitStack(Stack &s);
bool IsEmpty(Stack &s);
bool Push(Stack &s, TreeNode* x);
bool Pop(Stack &s, TreeNode *&x);
bool GetTop(Stack &s, TreeNode *&x);

void InitQueue(Queue &q);
bool IsEmpty(Queue &q);
bool EnQueue(Queue &q, TreeNode *x);
bool DeQueue(Queue &q, TreeNode *&x);

void Init(Tree &tree);
TreeNode* CreateTree();
void sequence(TreeNode* r);

int main()
{
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    cout << "后序：";
    sequence(tree.root);
    return 0;
}

void InitStack(Stack &s)
{
    s.top = -1;
}

bool IsEmpty(Stack &s)
{
    return s.top == -1;
}

bool Push(Stack &s, TreeNode *x)
{
    if (s.top == MaxSize - 1)
        return false;
    s.data[++ s.top] = x;
    return true;
}

bool Pop(Stack &s, TreeNode *&x)
{
    if (IsEmpty(s))
        return false;
    x = s.data[s.top --];
    return true;
}

bool GetTop(Stack &s, TreeNode *&x)
{
    if (IsEmpty(s))
        return false;
    x = s.data[s.top];
    return true;
}

void InitQueue(Queue &q)
{
    q.front = q.rear = 0;
}

bool IsEmpty(Queue &q)
{
    return q.front == q.rear;
}

bool EnQueue(Queue &q, TreeNode *x)
{
    if (q.rear == MaxSize)
        return false;
    q.data[q.rear ++] = x;
    return true;
}

bool DeQueue(Queue &q, TreeNode *&x)
{
    if (IsEmpty(q))
        return false;
    x = q.data[q.front ++];
    return true;
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
        cout << "请输入左子树" << endl;
        root->leftson = CreateTree();
        cout << "请输入右子树" << endl;
        root->rightson = CreateTree();
        return root;
    }
}

void sequence(TreeNode* r)
{
    Stack s;
    InitStack(s);
    Queue q;
    InitQueue(q);
    EnQueue(q, r);
    while (!IsEmpty(q))
    {
        TreeNode *tmp;
        DeQueue(q, tmp);
        Push(s, tmp);
        if (tmp->leftson)
            EnQueue(q, tmp->leftson);
        if (tmp->rightson)
            EnQueue(q, tmp->rightson);
    }
    while (!IsEmpty(s))
    {
        TreeNode *t;
        Pop(s, t);
        cout << t->element << " ";
    }
}