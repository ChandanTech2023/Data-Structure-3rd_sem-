#include <iostream>
using namespace std;

class bst;
class node
{
    int data;
    node *left;
    node *right;

public:
    node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
    friend class bst;
};

class bst
{
    node *root;

public:
    bst()
    {
        root = nullptr;
    }
    ~bst() { delete root; }

    // Insertion of Element of Tree
    void insert(int element)
    {
        node *ptr = new node(element);
        if (root == nullptr)
            root = ptr;
        else
        {
            node *p = root, *parent;
            while (p != nullptr)
            {
                if (element < p->data)
                {
                    parent = p;
                    p = p->left;
                }
                else
                {
                    parent = p;
                    p = p->right;
                }
            }
            if (parent->data < element)
                parent->right = ptr;
            else
                parent->left = ptr;
        }
    }

    // Deletion of Node in Tree
    void deletion(int value)
    {
        node *p = root;
        deletion(p, value);
    }

    node *inOrderPre(node *p)
    {
        p = p->left;
        while (p->right != nullptr)
            p = p->right;
        return p;
    }

    node *deletion(node *p, int value)
    {
        node *ipre;
        if (p == nullptr)
            return nullptr;
        else if (p->left == nullptr && p->right == nullptr)
        {
            delete p;
            return nullptr;
        }

        if (value < p->data)
            p->left = deletion(p->left, value);
        else if (value > p->data)
            p->right = deletion(p->right, value);
        else
        {
            ipre = inOrderPre(p);
            p->data = ipre->data;
            p->left = deletion(p->left, ipre->data);
        }
        return p;
    }

    // Number of Node in Tree
    int numNode()
    {
        node *p = root;
        return numNode(p);
    }
    int numNode(node *p)
    {
        int c = 0;
        if (p == nullptr)
            return 0;
        if (p != nullptr)
            c++;
        else if (p->left != nullptr)
            c++;
        else if (p->right != nullptr)
            c++;

        c += numNode(p->left) + numNode(p->right);
        return c;
    }

    // Height of Tree
    int height()
    {
        node *p = root;
        return height(p);
    }

    int height(node *p)
    {
        if (p == nullptr)
            return 0;
        else
        {
            int leftnum = height(p->left);
            int righttnum = height(p->right);
            return 1 + max(leftnum, righttnum);
        }
    }

    // Number of Left Node in Tree
    int sizeLeftNode()
    {
        node *p = root;
        return sizeLeftNode(p);
    }
    int sizeLeftNode(node *p)
    {
        int c = 0;
        if (p == nullptr)
            return 0;
        else if (p->left != nullptr)
            c++;
        c += sizeLeftNode(p->left) + sizeLeftNode(p->right);
        return c;
    }

    // Number of Right Node in Tree
    int sizeRightNode()
    {
        node *p = root;
        return sizeRightNode(p);
    }

    int sizeRightNode(node *p)
    {
        int c = 0;
        if (p == nullptr)
            return 0;
        else if (p->right != nullptr)
            c++;
        c += sizeRightNode(p->left) + sizeRightNode(p->right);
        return c;
    }
    // Display or Traverse of Tree
    void display()
    {
        node *p = root;
        display(p);
        cout<<endl;
    }
    void display(node *p)
    {
        if (p == nullptr)
            return;
        else
        {
            display(p->left);
            cout << p->data << " ";
            display(p->right);
        }
    }
};

int main()
{
    bst b;
    int option, n;
    while (true)
    {
        cout << "Choose any one : \n1.Insert \n2.Tarverse \n3.Deletion \n4.Height of Tree \n5.Number of Node in Tree \n";
        cout << "6.Number of Left Node\n7.Number of Right Node \n0.Exit\n";
        cin >> option;
        if (option == 1)
        {
            cout << "Enter element : ";
            cin >> n;
            b.insert(n);
        }
        else if (option == 2)
            b.display();
        else if (option == 3)
        {
            cout << "Enter element : ";
            cin >> n;
            b.deletion(n);
        }
        else if (option == 4)
            cout << "Height of Tree : " << b.height()<<endl;
        else if (option == 5)
            cout << "Number of Node in Tree : " << b.numNode() << endl;
        else if (option == 6)
            cout << "Number of Left Node in Tree : " << b.sizeLeftNode() << endl;
        else if (option == 7)
            cout << "Number of Right Node in Tree : " << b.sizeRightNode() << endl;
        else if (option == 0)
            break;
        else
            cout << "Invalid input!\n";
    }
    // b.insert(56);
    // b.insert(89);
    // b.insert(23);
    // b.insert(78);
    // b.insert(45);
    // b.insert(94);
    // b.insert(12);
    // b.insert(60);
    // b.insert(92);
    // b.insert(91);
    // b.display();
    // cout<<"After Remove Element \n";
    // b.deletion(94);
    // b.display();

    return 0;
}