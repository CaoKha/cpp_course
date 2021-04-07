#include <iostream>
#include <map>

std::map<char, int> valtab = {
    {'A', 3},
    {'B', 4}};

class Tree;
class Node
{
    friend class Tree;
    friend std::ostream &operator<<(std::ostream &, const Tree &);
    int use; // reference count -GC
public:
    Node() { use = 1; }
    virtual void print(std::ostream &) = 0; // pure virtual
    virtual ~Node() {}                      // virtual destructor
    virtual int eval() = 0;                 // pure virtual = to be overwritten
};

class Tree
{
    friend class Node;
    friend std::ostream &operator<<(std::ostream &, const Tree &);
    Node *p; // polymorphic hierachy
public:
    Tree(int);                // constant
    Tree(char);               // variable
    Tree(char *, Tree);       // unary operator
    Tree(char *, Tree, Tree); // binary operator
    Tree(const Tree &t)
    {
        p = t.p;
        ++p->use;
    } // copy constructor
    ~Tree()
    {
        if (--p->use == 0)
            delete p;
    }
    void operator=(const Tree &t);
    int eval() { return p->eval(); }
};

std::ostream &operator<<(std::ostream &o, const Tree &t)
{
    t.p->print(o);
    return (o);
}

class LeafNode : public Node
{
    friend class Tree;
    void print(std::ostream &o) = 0;
    virtual int eval() = 0;
};

class IntNode : public LeafNode
{
    friend class Tree;
    int n;
    void print(std::ostream &o) { o << n; }
    IntNode(int k) : n(k) {}

public:
    int eval() { return n; }
};

class IdNode : public LeafNode
{
    friend class Tree;
    char name;
    void print(std::ostream &o) { o << name; }

public:
    IdNode(char id) : name(id) {}
    int eval() { return valtab[name]; }
};

// Unary operator
class UnaryNode : public Node
{
    friend class Tree;
    char *op;
    Tree opnd;
    UnaryNode(char *a, Tree b) : op(a), opnd(b) {}
    void print(std::ostream &o) { o << "(" << op << opnd << ")"; }

public:
    int eval();
};

int UnaryNode::eval()
{
    switch (op[0])
    {
    case '-':
        return (-opnd.eval());
    case '+':
        return (+opnd.eval());
    default:
        std::cerr << "no operand\n"
                  << std::endl;
        return 0;
    }
}

// Binary operator
class BinaryNode : public Node
{
    friend Tree;
    char *op;
    Tree left;
    Tree right;
    BinaryNode(char *a, Tree b, Tree c) : op(a), left(b), right(c) {}
    void print(std::ostream &o) { o << "(" << left << op << right << ")"; }

public:
    int eval();
};

int BinaryNode::eval()
{
    switch (op[0])
    {
    case '-':
        return (left.eval() - right.eval());
    case '+':
        return (left.eval() + right.eval());
    case '*':
        return (left.eval() * right.eval());
    default:
        std::cerr << "no operand\n"
                  << std::endl;
        return 0;
    }
}

Tree::Tree(int n)
{
    p = new IntNode(n);
}

Tree::Tree(char id)
{
    p = new IdNode(id);
}

Tree::Tree(char *op, Tree t)
{
    p = new UnaryNode(op, t);
}

Tree::Tree(char *op, Tree left, Tree right)
{
    p = new BinaryNode(op, left, right);
}

int main()
{
    Tree t1 = Tree("*", Tree("-", 5), Tree("+", 'A', 4));
    Tree t2 = Tree("+", Tree("-", 'A', 1), Tree("+", t1, 'B'));
    std::cout << "t1 = " << t1 << "; t2 = " << t2 << std::endl;
    std::cout << "t1: " << t1.eval() << " t2: " << t2.eval() << std::endl;
}