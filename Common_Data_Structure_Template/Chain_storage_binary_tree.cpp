/*
 * ��������ʽ�洢
 * ���ӣ�
 *
    ����2 1 7 6 5 3
    �ݹ�д����
    ����2 1 6 7 5 3
    ����1 6 2 3 5 7
    ����6 1 3 5 7 2
    �ǵݹ�д����
    ����2 1 6 7 5 3
    ����1 6 2 3 5 7
    ����6 1 3 5 7 2
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
// todo
bool search (Tree &tree, int x);
// �ݹ�
void Porder(TreeNode* r); // ����
void inorder(TreeNode* r); // ����
void epilogue(TreeNode* r); // ����
void sequence(TreeNode* r); // ����
// �ǵݹ�
void Porder1(TreeNode* r);
void inorder1(TreeNode* r);
void epilogue1(TreeNode* r);

int main()
{
    Tree tree;
    puts("��������ڵ�");
    tree.root = CreateTree();
    cout << "����";
    sequence(tree.root);
    puts("");
    puts("�ݹ�д����");
    cout << "����" ;
    Porder(tree.root);
    puts("");
    cout << "����";
    inorder(tree.root);
    puts("");
    cout << "����";
    epilogue(tree.root);
    puts("");
    puts("�ǵݹ�д����");
    cout << "����" ;
    Porder1(tree.root);
    puts("");
    cout << "����";
    inorder1(tree.root);
    puts("");
    cout << "����";
    epilogue1(tree.root);
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
        cout << "������������" << endl;
        root->leftson = CreateTree();
        cout << "������������" << endl;
        root->rightson = CreateTree();
        return root;
    }
}

bool search (Tree &tree, int x)
{
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

void inorder(TreeNode* r)
{
    if (!r)
        return ;
    inorder(r->leftson);
    cout << r->element << " ";
    inorder(r->rightson);
}

void epilogue(TreeNode* r)
{
    if (!r)
        return ;
    epilogue(r->leftson);
    epilogue(r->rightson);
    cout << r->element << " ";
}

void sequence(TreeNode* r)
{
    Queue q;
    InitQueue(q);
    EnQueue(q, r);
    while (!IsEmpty(q))
    {
        TreeNode* tmp;
        DeQueue(q, tmp);
        cout << tmp->element << " ";
        if (tmp->leftson)
            EnQueue(q, tmp->leftson);
        if (tmp->rightson)
            EnQueue(q, tmp->rightson);
    }
}

void Porder1(TreeNode* r)
{
    Stack s;
    InitStack(s);
    TreeNode *p = r;
    while (p || !IsEmpty(s))
    {
        if (p)
        {
            cout << p->element << " ";
            Push(s, p);
            p = p->leftson;
        }
        else
        {
            Pop(s, p);
            p = p->rightson;
        }
    }
}

void inorder1(TreeNode* r)
{
    Stack s;
    InitStack(s);
    TreeNode *p = r;
    while (p || !IsEmpty(s))
    {
        if (p)
        {
            Push(s, p);
            p = p->leftson;
        }
        else
        {
            Pop(s, p);
            cout << p->element << " ";
            p = p->rightson;
        }
    }
}

void epilogue1(TreeNode* r)
{
    Stack s;
    InitStack(s);
    TreeNode *p = r;
    TreeNode *t = NULL;
    while (p || !IsEmpty(s))
    {
        if (p)
        {
            Push(s, p);
            p = p->leftson;
        }
        else
        {
            GetTop(s, p);
            if (p->rightson && p->rightson != t)
                p = p->rightson;
            else
            {
                Pop(s, p);
                cout << p->element << " ";
                t = p;
                p = NULL;
            }
        }
    }
}
