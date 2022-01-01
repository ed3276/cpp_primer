#include <iostream>
using namespace std;

class PolyNode;
class Poly;
Poly operator+(const Poly &p1, const Poly &p2);
Poly operator*(const PolyNode &pn1, const Poly &p2);
Poly operator*(const Poly &p1, const Poly &p2);
ostream &operator<<(ostream &os, const Poly &e);
class PolyNode
{
    friend class Poly;
    friend Poly operator+(const Poly &p1, const Poly &p2);
    friend Poly operator*(const PolyNode &pn1, const Poly &p2);
    friend Poly operator*(const Poly &p1, const Poly &p2);
    friend ostream &operator<<(ostream &os, const Poly &e);
public:
    PolyNode(int c, int e, PolyNode *n=nullptr) : coef(c), exp(e), next(n){ }
    ~PolyNode()=default;
private:
    int coef;
    int exp;
    PolyNode *next;
};
class Poly
{
    friend Poly operator+(const Poly &p1, const Poly &p2);
    friend Poly operator*(const PolyNode &pn1, const Poly &p2);
    friend Poly operator*(const Poly &p1, const Poly &p2);
    friend ostream &operator<<(ostream &os, const Poly &e);
    public:
    Poly() : num(0), p(new PolyNode(0,0)){ }
    ~Poly();
    Poly(istream &is);
    Poly(const Poly &rhs);
    Poly &operator=(const Poly &rhs);
    private:
    int num;
    PolyNode *p;
};
Poly::~Poly()
{
    if(num > 0) {
        PolyNode *t = p->next;
        while(t){
            p->next = t->next;
            delete t;
            t = p->next;
        }
        delete p;
        p = 0;
        num = 0;
    }
}
Poly::Poly(istream &is):num(0),p(new PolyNode(0,0))
{
    is >> num;
    PolyNode *t = p;
    int c,e;
    for(int i = 0; i != num; ++i){
        is >> c >> e;
        t->next=new PolyNode(c,e);
        t=t->next;
    }
}
Poly::Poly(const Poly &rhs) : num(rhs.num),p(new PolyNode(0,0))
{
    PolyNode *t1 = p, *t2 = rhs.p->next;
    while(t2){
        t1->next=new PolyNode(t2->coef,t2->exp);
        t1=t1->next;
        t2=t2->next;
    }
}
Poly &Poly::operator=(const Poly &rhs)
{
    if(&rhs == this) return *this;
    Poly tmp = rhs;
    if(num > 0) {
        PolyNode *t = p->next;
        while(t){
            p->next = t->next;
            delete t;
            t = p->next;
        }
    }
    PolyNode *t1 = p, *t2 = rhs.p->next;
    while(t2){
        t1->next=new PolyNode(t2->coef,t2->exp);
        t1=t1->next;
        t2=t2->next;
    }
    num = rhs.num;
    return *this;
}
Poly operator+(const Poly &p1, const Poly &p2)
{
    Poly ans;
    PolyNode *t=ans.p;
    PolyNode *i1=p1.p->next,*i2=p2.p->next;
    while(i1 && i2){
        if(i1->exp > i2->exp){
            t->next = new PolyNode(i1->coef,i1->exp);
            ++ans.num;
            t = t->next;
            i1 = i1->next;
        }
        else if(i1->exp < i2->exp){
            t->next = new PolyNode(i2->coef,i2->exp);
            ++ans.num;
            t = t->next;
            i2 = i2->next;
        }
        else {
            int sum = i1->coef + i2->coef;
            if(sum){
                t->next = new PolyNode(sum,i2->exp);
                ++ans.num;
                t = t->next;
            }
            i1 = i1->next;
            i2 = i2->next;
        }
    }
    while(i1){
        t->next = new PolyNode(i1->coef,i1->exp);
        ++ans.num;
        t = t->next;
        i1 = i1->next;
    }
    while(i2){
        t->next = new PolyNode(i2->coef,i2->exp);
        ++ans.num;
        t = t->next;
        i2 = i2->next;
    }
    return ans;
}
Poly operator*(const PolyNode &pn1, const Poly &p2)
{
    Poly ans;
    PolyNode *t = ans.p;
    PolyNode *t2 = p2.p->next;
    int e, c;
    while(t2){
        e = pn1.exp + t2->exp;
        c = pn1.coef * t2->coef;
        if (c){
            t->next = new PolyNode(c,e);
            ++ans.num;
            t = t->next;
        }
        t2 = t2->next;
    }
    return ans;
}
Poly operator*(const Poly &p2, const PolyNode &pn1)
{
    return pn1*p2;
}
Poly operator*(const Poly &p1, const Poly &p2)
{
    Poly ans;
    PolyNode *t1 = p1.p->next;
    while(t1){
        ans = ans + (*t1)*p2;
        t1 = t1->next;
    }
    return ans;
}
ostream &operator<<(ostream &os, const Poly &e)
{
    if(e.num>0){
        PolyNode *t = e.p->next;
        while(t){
            os << t->coef << " " << t->exp << " ";
            t=t->next;
        }
    }
    else os << 0 << " " << 0 << " ";
    return os;
}
int main()
{
    Poly p1(std::cin), p2(std::cin);
    std::cout << p1*p2 << std::endl;
    std::cout << p1+p2;
}
