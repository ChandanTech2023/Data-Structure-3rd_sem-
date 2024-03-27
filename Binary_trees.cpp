#include <iostream>
using namespace std;

class bst;
class bstnode
{
    int info;
    bstnode *left;
    bstnode *right;

public:
    bstnode(int d)
    {
        info = d;
        left = nullptr;
        right = nullptr;
    }
    friend class bst;
};

class bst
{
    bstnode *root;
    int size;

public:
    bst()
    {
        root = nullptr;
    }

    void insert(int x)
    {
        bstnode *p = new bstnode(x);
        bstnode *q, *parent;
        if (root == nullptr)
            root = p;
        else
        {
            q = root;
            while (q != nullptr)
            {
                if (x < q->info)
                {
                    parent = q;
                    q = q->left;
                }
                else
                {
                    parent = q;
                    q = q->right;
                }
            }
            if (x > parent->info)
            {
                parent->right = p;
            }
            else
            {
                parent->left = p;
            }
        }
    }
    void display()
    {
        bstnode *p = root;
        if (p == nullptr)
        {
            cout << "Trees is Empty!\n";
            return;
        }
        traversePre(p);
        cout<<endl;
        traverseIn(p);
        cout<<endl;
        traversePos(p);
    }

    void traversePre(bstnode *p)
    {
        if (p == nullptr)
            return;
        else
        {
            cout << p->info << " ";
            traversePre(p->left);
            traversePre(p->right);
        }
    }
    void traverseIn(bstnode *p)
    {
        if (p == nullptr)
            return;
        else
        {
            traverseIn(p->left);
            cout << p->info << " ";
            traverseIn(p->right);
        }
    }
    void traversePos(bstnode *p)
    {
        if (p == nullptr)
            return;
        else
        {
            traversePos(p->left);
            traversePos(p->right);
            cout << p->info << " ";
        }
    }
};

int main()
{
    bst b;
    b.insert(45);
    b.insert(29);
    b.insert(30);
    b.insert(48);
    b.insert(40);
    b.insert(20);
    b.insert(47);
    b.insert(25);
    b.display();
    return 0;
}