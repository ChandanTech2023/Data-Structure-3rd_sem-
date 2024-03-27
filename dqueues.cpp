#include <iostream>
using namespace std;
template<class T>
class Dqueue;

template<class T>
class Node
{
    T data;
    Node<T> *prev;
    Node<T> *next;

public:
    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }
    friend class Dqueue<T>;
};

template<class T>
class Dqueue
{
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Dqueue()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    bool isEmpty()
    {
        return head == nullptr;
    }

    int sizeDqueue()
    {
        return size;
    }

    void insertFront(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
        size++;
    }

    void insertBack(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
        {
            head = ptr;
            tail = ptr;
        }
        else
        {
            tail->next = ptr;
            ptr->prev = tail;
            tail = ptr;
        }
        size++;
    }

    T eraseFront()
    {
        Node<T> *p = head;
        if (p == nullptr)
        {
            cout << "Dqueue Empty!\n";
            return false;
        }
        else
        {
            Node<T> *q = head;
            T value = q->data;
            head = head->next;
            head->prev = nullptr;
            size--;
            delete q;
            return value;
        }
    }

    T eraseBack()
    {
        Node<T> *p = tail;
        if (p == nullptr)
        {
            cout << "Dqueue Empty!\n";
            return false;
        }
        else
        {
            Node<T> *q = tail;
            T value = q->data;
            tail = tail->prev;
            tail->next = nullptr;
            size--;
            delete q;
            return value;
        }
    }

    T front()
    {
        if (head == nullptr)
        {
            cout << "Dqueue Empty!\n";
            return false;
        }
        else
            return head->data;
    }

    T back()
    {
        if (!tail)
        {
            cout << "Dqueue Empty!\n";
            return false;
        }
        else
            return tail->data;
    }

    void display()
    {
        Node<T> *p = head;
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
    Dqueue<int> d;
    d.insertFront(45);
    d.insertFront(23);
    d.insertFront(90);
    d.insertFront(67);
    d.insertFront(26);
    d.insertFront(83);
    d.insertFront(50);
    d.insertBack(4);
    d.insertBack(7);
    d.insertBack(8);
    d.insertBack(9);
    d.insertBack(10);
    d.display();
    cout << "Size of Dqueue : " << d.sizeDqueue() << endl;
    d.eraseBack();
    d.display();
    d.eraseFront();
    d.display();
    cout << "Front Element of Dqueue : " << d.front() << endl;
    cout << "Back Element of Dqueue : " << d.back() << endl;
    cout << "Size of Dqueue : " << d.sizeDqueue() << endl;
    return 0;
}