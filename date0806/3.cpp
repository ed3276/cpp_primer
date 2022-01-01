struct Node
{
    Node(int v = 0, int n = -1):val(v), next(n){ }
    int val;
    int next;
};
struct List
{
    List(istream &is);
    ~List(){delete [] node;}
    int reverse(int k);
    int num;
    int head;
    Node *node;
};
List::List(istream &is, int haddr, int num)
{
    head = haddr;
    head = new Node[100000];
    int addr, val, next;
    for (int i=0; i!= num; ++i){
        is >> addr >> val >> next;
        node[addr].val = val;
        node[addr].next = next;
    }
}
int List::reverse(int head, int k)
{
    int neu = head;
    int old = node[neu].next;
    int tmp;
    int cnt = 1;
    while (cnt < k){
        tmp = node[old].next;
        node[old].next = neu;
        neu = old;
        old = tmp;
    }
    node[head].next = old;
    return neu;
}
