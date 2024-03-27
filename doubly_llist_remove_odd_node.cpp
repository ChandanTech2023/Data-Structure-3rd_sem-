#include <iostream>
using namespace std;

template<class T>
class dll;
template<class T>
class Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;

public:
    Node(T d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
    friend class dll<T>;
};

template<class T>
class dll
{
    Node<T> *head;

public:
    dll()
    {
        head = nullptr;
    }
    void insert(T key)
    {
        Node<T> *ptr = new Node<T>(key);
        if (!head)
        {
            head = ptr;
        }
        else
        {
            Node<T> *p = head;
            while (p->next != nullptr)
            {
                p = p->next;
            }
            p->next = ptr;
            ptr->prev = p;
        }
    }

    void odd_delete()
    {
        Node<T> *odd = head, *even;
        head = head->next;
        even = odd->next;
        odd = even->next;
        head->prev = nullptr;
        while (odd->next != nullptr)
        {
            even->next = odd->next;
            odd->next->prev = even;
            delete odd;
            even = even->next;
            if (even->next == nullptr)
                break;
            odd = even->next;
        }
        if (odd->next == nullptr)
        {
            even->next = nullptr;
            odd->prev = nullptr;
            delete odd;
        }
    }

    void display()
    {
        Node<T> *p = head, *q;
        while (p != nullptr)
        {
            cout << p->data << " ";
            q = p;
            p = p->next;
        }
        cout << endl;
        while (q != nullptr)
        {
            cout << q->data << " ";
            q = q->prev;
        }
        cout << endl;
    }
};

int main()
{
    dll<int> l;
    l.insert(12);
    l.insert(89);
    l.insert(45);
    l.insert(67);
    l.insert(34);
    l.insert(70);
    l.insert(20);
    l.insert(27);
    l.display();
    l.odd_delete();
    l.display();
    return 0;
}