#include <iostream>
using namespace std;

class ollist;
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
    friend class ollist;
};

class ollist
{
    Node *head;

public:
    ollist()
    {
        head = nullptr;
    }

    void insertOreded(int key)
    {
        Node *ptr = new Node(key);
        if (!head)
            head = ptr;
        else
        {
            Node *p = head, *q;
            if (p->data > key)
            {
                ptr->next = head;
                head = ptr;
            }
            else
            {
                while (p->data < key)
                {
                    q = p;
                    p = p->next;
                    if (!p)
                        break;
                }
                ptr->next = q->next;
                q->next = ptr;
            }
        }
    }

    ollist merge(ollist ll)
    {
        Node *r = nullptr;
        Node *p = head;
        Node *q = ll.head;
        ollist newll;
        if (!p)
        {
            newll.head = ll.head;
            return newll;
        }
        if (!q)
        {
            newll.head = head;
            return newll;
        }

        if (p->data < q->data)
        {
            r = p;
            p = p->next;
        }
        else
        {
            r = q;
            q = q->next;
        }
        newll.head = r;
        while (p != nullptr && q != nullptr)
        {
            if (p->data < q->data)
            {
                r->next = p;
                r = p;
                p = p->next;
            }
            else
            {
                r->next = q;
                r = q;
                q = q->next;
            }
        }
        if (!p)
            r->next = q;
        else
            r->next = p;

        return newll;
    }

    void odd_remove()
    {
        Node *odd = head, *even;
        head = head->next;
        even = odd->next;
        odd = even->next;
        while (even != nullptr && odd != nullptr)
        {
            even->next = odd->next;
            even = even->next;
            odd = even->next;
        }
    }

    void display()
    {
        Node *p = head;
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main()
{
    ollist l, l1, l2;
    l.insertOreded(66);
    l.insertOreded(23);
    l.insertOreded(667);
    l.insertOreded(45);
    l.insertOreded(67);
    l.insertOreded(12);
    l.insertOreded(56);
    l.insertOreded(89);
    l.display();
    l1.insertOreded(60);
    l1.insertOreded(34);
    l1.insertOreded(8);
    l1.insertOreded(0);
    l1.insertOreded(3);
    l1.insertOreded(4);
    l1.insertOreded(6);
    l1.insertOreded(357657);
    l1.display();
    l2 = l.merge(l1);
    l2.display();
    l2.odd_remove();
    l2.display();
    return 0;
}