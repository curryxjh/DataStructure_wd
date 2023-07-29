/*
 * 带头结点的单循环链表实现多项式加法
 */
#include <iostream>

struct Node
{
    int coef;
    int exp;
    Node* link;
};

struct Ploy
{
    Node* head;
};

void Create(Ploy* p);
void Add(Ploy* p, Ploy* q);
bool Print(Ploy* L);

int main()
{
    Ploy* p, * q;
    Create(p);
    Create(q);
    Add(p, q);

    return 0;
}

void Create(Ploy* p)
{
    Node* pn, *pre, *q;
    p->head = new Node;
    p->head->exp = -1;
    p->head->link = p->head;
    while(true)
    {
        pn = new Node;
        std::cout << "coef: " ;
        std::cin >> pn->coef;
        std::cout << "exp: ";
        std::cin >> pn->exp;
        if (pn->exp < 0)
            break;
        pre = p->head;
        q = p->head->link;
        while (q && q->exp > pn->exp)
        {
            pre = q;
            q = q->link;
        }
        pn->link = q;
        pre->link = pn;
    }
}

void Add(Ploy* p, Ploy* q)
{

}


bool Print(Ploy* L)
{
    Node* p;
    if (!L->head)
        return false;
    p = L->head->link;
    while(p)
    {
        if(p->link)
            std::cout << p->coef << "x^" << p->exp  << "+";
        else
            std::cout << p->coef << "x^" << p->exp;
        p = p->link;
    }
    puts("");
    return true;
}