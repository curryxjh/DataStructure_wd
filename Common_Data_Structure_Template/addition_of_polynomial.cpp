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
    Ploy* p = new Ploy;
    Ploy* q = new Ploy;
    Create(p);
    Create(q);
    Add(p, q);
    Print(q);
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

void Add(Ploy* pploy, Ploy* qploy)
{
    Node* q, *q1 = qploy->head, *p;
    Node* tmp;
    q = q1->link;
    p = pploy->head->link;
    while (p->exp >= 0)
    {
        while (q->exp > p->exp)
        {
            q1 = q;
            q = q->link;
        }
        if (q->exp == p->exp)
        {
            q->coef += p->coef;
            if (! q->coef)
            {
                q1 ->link = q->link;
                Node* t = q;
                q = q1->link;
                p = p->link;
                delete t;
            }
            else
            {
                q1 = q;
                q = q->link;
                p = p->link;
            }
        }
        else if (q->exp < p->exp)
        {
            tmp = new Node;
            tmp->coef = p->coef;
            tmp->exp = p->exp;
            tmp->link = q1->link;
            q1->link = tmp;
            q1 = q1->link;
            p = p->link;
        }
    }
}


bool Print(Ploy* L)
{
    Node* p;
    if (!L->head)
        return false;
    p = L->head->link;
    while(p != L->head)
    {
        if(p->link != L->head)
            std::cout << p->coef << "x^" << p->exp  << "+";
        else
            std::cout << p->coef << "x^" << p->exp;
        p = p->link;
    }
    puts("");
    return true;
}