/*
 * p12
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

void InitStack(Stack &s);
bool IsEmpty(Stack &s);
bool Push(Stack &s, TreeNode* x);
bool Pop(Stack &s, TreeNode *&x);
bool GetTop(Stack &s, TreeNode *&x);


void Init(Tree &tree);
TreeNode* CreateTree();
void Find_ancestor(TreeNode *&r, int x);
Stack s;

int main()
{
    InitStack(s);
    Tree tree;
    puts("请输入根节点");
    tree.root = CreateTree();
    cout <<"寻找祖先的的值：";
    int x;
    cin >> x;
    Find_ancestor(tree.root, x);
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

void Find_ancestor(TreeNode *&r, int x)
{
    if (! r)
        return;
    if (r->element == x)
    {
        while (! IsEmpty(s))
        {
            TreeNode *tmp;
            Pop(s, tmp);
            cout << tmp->element << " ";
        }
    }
    Push(s, r);
    if (! r->leftson && ! r->rightson)
    {
        TreeNode *t;
        Pop(s, t);
        return ;
    }
    Find_ancestor(r->leftson, x);
    Find_ancestor(r->rightson, x);
}