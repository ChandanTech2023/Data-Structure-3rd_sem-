#include <iostream>
using namespace std;
class bst;
class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
    friend class bst;
};

class bst
{
    Node *root;

public:
    bst()
    {
        root = nullptr;
    }

    // Insertion in Recrusive Approch
    void insert(int key)
    {
        Node *parent;
        insert(root, parent, key);
    }
    void insert(Node *p, Node *parent, int key)
    {
        if (p == nullptr)
        {
            Node *ptr = new Node(key);
            if (root == nullptr)
                root = ptr;
            else if (parent->data < key)
                parent->right = ptr;
            else if (parent->data > key)
                parent->left = ptr;
        }
        else if (p->data > key)
        {
            parent = p;
            insert(p->left, parent, key);
        }
        else if (p->data < key)
        {
            parent = p;
            insert(p->right, parent, key);
        }
    }

    void deletion(int value)
    {
        Node *p = root;
        deletion(p, value);
    }
    Node *inOrder(Node *p)
    {
        p = p->left;
        while (p->right != nullptr)
            p = p->right;
        return p;
    }
    Node *deletion(Node *p, int key)
    {
        Node *ipre;
        if (p == nullptr)
            return nullptr;
        else if (p->right == nullptr && p->left == nullptr)
        {
            delete p;
            return nullptr;
        }

        if (p->data > key)
            p->left = deletion(p->left, key);
        else if (p->data < key)
            p->right = deletion(p->right, key);
        else
        {
            ipre = inOrder(p);
            p->data = ipre->data;
            p->left = deletion(p->left,ipre->data);
        }
        return p;
    }
    // Display Using Recursive
    void display()
    {
        Node *p = root;
        display(p);
        cout << endl;
    }
    void display(Node *p)
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

    // Search Element in BST
    void search(int key)
    {
        Node *p = root;
        p = search(p, key);
        if (!p)
            printf("%d Value not found!\n", key);
        else
            printf("%d Value is found in BST!\n", key);
    }
    Node *search(Node *p, int key)
    {
        if (p == nullptr)
            return p;
        if (p->data == key)
            return p;
        else if (p->data < key)
            return search(p->right, key);
        else if (p->data > key)
            return search(p->left, key);
        return p;
    }
};

int main()
{
    bst b;
    b.insert(45);
    b.insert(23);
    b.insert(665);
    b.insert(89);
    b.insert(67);
    b.insert(206);
    b.insert(94);
    b.insert(6);
    b.insert(4345);
    b.insert(34);
    b.insert(679);
    b.insert(40);
    b.insert(39);
    b.display();
    // b.search(94);
    // b.search(940);
    b.deletion(94);
    b.display();
    return 0;
}