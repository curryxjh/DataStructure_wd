#include <iostream>
struct Node
{
    char data;
    Node* lchild, *rchild;
};

struct Tree
{
    Node *tree;
};

void BuildTree(Node *&t);
void isAVL(Node *t, int &bal, int &h);
// todo test

int main()
{
    Tree t;
    BuildTree(t.tree);
    int b, h;
    isAVL(t.tree, b, h);
    if (b)
        puts("YES");
    else
        puts("NO");
    return 0;
}

void BuildTree(Node *&t)
{
    char ch;
    std::cin >> ch;
    if (ch == '#')
        t = NULL;
    else
    {
        t = new Node;
        t->data = ch;
        t->lchild = t->rchild = NULL;
        BuildTree(t->lchild);
        BuildTree(t->rchild);
    }
}

void isAVL(Node *t, int &bal, int &h)
{
    int h1, h2, b1, b2;
    if (!t)
    {
        h = 0;
        bal = 1;
    }
    else if (t->lchild && t->rchild)
    {
        h = 1;
        bal = 1;
    }
    else
    {
        isAVL(t->lchild, bal, h1);
        isAVL(t->rchild, bal, h2);
        h = (h1 > h2 ? h1 : h2) + 1;
        if (abs(h1 - h2) < 2)
            bal = b1 && b2;
        else
            bal = 0;
    }
}