#include <iostream>
using namespace std;
template <class T>
class clList;
template <class T>
class Node
{
    T data;
    Node *next;

public:
    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
    friend class clList<T>;
};

template <class T>
class clList
{
    Node<T> *head;

public:
    clList()
    {
        head = nullptr;
    }
    void insertAtBegin(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
        {
            head = ptr;
            head->next = ptr;
        }
        else
        {
            Node<T> *tail = head;
            while (tail->next != head)
                tail = tail->next;
            tail->next = ptr;
            ptr->next = head;
            head = ptr;
        }
    }

    void insertAtEnd(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
        {
            head = ptr;
            head->next = ptr;
        }
        else
        {
            Node<T> *p = head;
            while (p->next != head)
                p = p->next;
            p->next = ptr;
            ptr->next = head;
        }
    }

    void insertAtPosition(int position, T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
        {
            head = ptr;
            head->next = ptr;
        }
        else
        {
            Node<T> *p = head;
            int c = 1;
            while (c != position)
            {
                p = p->next;
                c++;
            }
            ptr->next = p->next;
            p->next = ptr;
        }
    }

    void insertAtValue(T value, T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
        {
            head = ptr;
            head->next = ptr;
        }
        else
        {
            Node<T> *p = head;
            while (p->data != value)
                p = p->next;
            ptr->next = p->next;
            p->next = ptr;
        }
    }

    void deletionAtBegin()
    {
        Node<T> *p = head;
        Node<T> *q = head;
        if (head == nullptr)
        {
            cout << "Circular Linked List is Empty!\n";
            return;
        }
        head = head->next;
        while (q->next->next != head)
            q = q->next;
        q->next = head;
        delete p;
    }

    void deletionAtEnd()
    {
        Node<T> *p = head;
        Node<T> *q = head;
        if (head == nullptr)
        {
            cout << "Circular Linked List is Empty!\n";
            return;
        }
        while (p->next->next != head)
            p = p->next;
        q = p->next;
        p->next = head;
        delete q;
    }
    void deletionAtPosition(int position)
    {
        Node<T> *p = head, *q;
        int c = 1;
        if (head == nullptr)
        {
            cout << "Circular Linked List is Empty!\n";
            return;
        }
        while (c != position)
        {
            q = p;
            if (p->next == nullptr)
            {
                cout << "Position out of range!\n";
                return;
            }
            p = p->next;
            c++;
        }
        if (p == head)
            deletionAtBegin();
        else if (p->next != head)
            q->next = p->next;
        else if (p->next == head)
            deletionAtEnd();
        delete p;
    }

    void deletionAtValue(T value)
    {
        Node<T> *p = head, *q;
        if (head == nullptr)
        {
            cout << "Circular Linked List is Empty!\n";
            return;
        }
        while (p->data != value)
        {
            q = p;
            if (p->next == head)
            {
                cout << "Value not Found!\n";
                return;
            }
            p = p->next;
        }
        if (p == head)
            deletionAtBegin();
        else if (p->next != head)
            q->next = p->next;
        else if (p->next == head)
            deletionAtEnd();
        delete p;
    }

    void display()
    {
        Node<T> *p = head;
        if (p == nullptr)
        {
            cout << "*****Circular Linked List is Empty!*****\n";
            return;
        }
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
        cout << endl;
    }
};

inline int check(string str)
{
    for (char i : str)
        if (!isdigit(i) && i != '-')
            return 0;
    return 1;
}

inline int get()
{
    string str;
    int n;
    while (true)
    {
        cin >> str;
        if (check(str))
        {
            n = atoi(str.c_str());
            break;
        }
        else
        {
            cout << "Invalid! \ntry again!\n";
        }
    }
    return n;
}

int main()
{
    clList<int> l;

    int num, op, value, p;
    while (true)
    {
        cout << "Choose any one : \n"
             << "1.Insertion at Begin\n"
             << "2.Insertion at End\n"
             << "3.Insertion at Position\n"
             << "4.Insertion ar After Value\n"
             << "5.Deletion at Begin\n"
             << "6.Deletion at End\n"
             << "7.Deletion at Position\n"
             << "8.Deletion at value\n"
             << "9.Display\n"
             << "0.Exit\n";
        op = get();
        if (op == 1)
        {
            cout << "Enter Element : ";
            num = get();
            l.insertAtBegin(num);
        }
        else if (op == 2)
        {
            cout << "Enter Element : ";
            num = get();
            l.insertAtEnd(num);
        }
        else if (op == 3)
        {
            cout << "Enter Element : ";
            num = get();
            cout << "Enter Position : ";
            p = get();
            l.insertAtPosition(p, num);
        }
        else if (op == 4)
        {
            cout << "Enter Element : ";
            num = get();
            cout << "Enter Value : ";
            value = get();
            l.insertAtValue(value, num);
        }
        else if (op == 5)
            l.deletionAtBegin();
        else if (op == 6)
            l.deletionAtEnd();
        else if (op == 7)
        {
            cout << "Enter Position : ";
            p = get();
            l.deletionAtPosition(p);
        }
        else if (op == 8)
        {
            cout << "Enter Value : ";
            value = get();
            l.deletionAtValue(value);
        }
        else if (op == 9)
            l.display();
        else if (op == 0)
            break;
        else
            cout << "Invalid Option!\n";
    }
    return 0;
}