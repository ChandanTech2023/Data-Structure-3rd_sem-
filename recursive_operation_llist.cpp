#include <iostream>
using namespace std;

class llist;

class Node
{
    int data;
    Node *next;

public:
    Node(int d)
    {
        data = d;
        next = nullptr;
    }

    friend class llist;
};

class llist
{
    Node *head;

public:
    llist()
    {
        head = nullptr;
    }
    void insert(int d)
    {
        Node *ptr = new Node(d);
        if (!head)
            head = ptr;
        else
        {
            ptr->next = head;
            head = ptr;
        }
    }
    void reverse()
    {
        Node *p = head;
        Node *q = p->next;
        p->next = nullptr;
        Node *r = q->next;
        reverse(p, q, r);
    }
    void reverse(Node *p, Node *q, Node *r)
    {
        if (q->next == nullptr)
        {
            q->next = p;
            head = q;
        }
        else
        {
            q->next = p;
            reverse(q, r, r->next);
        }
    }
    int length()
    {
        Node *p = head;
        return length(p);
    }
    int length(Node *p)
    {
        if (!p)
            return 0;
        else
            return 1 + length(p->next);
    }

    void display()
    {
        Node *p = head;
        display(p);
        cout << endl;
    }
    void display(Node *p)
    {
        if (p == nullptr)
            return;
        else
        {
            cout << p->data << " ";
            display(p->next);
        }
    }
};

int main()
{
    llist l;
    l.insert(23);
    l.insert(12);
    l.insert(67);
    l.insert(89);
    l.insert(90);
    l.insert(37);
    l.insert(90);
    l.insert(20);
    l.display();
    l.reverse();
    l.display();
    cout << "Length of Linked List : " << l.length() << endl;
    return 0;
}