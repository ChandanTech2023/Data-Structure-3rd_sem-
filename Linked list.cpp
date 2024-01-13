#include <iostream>
using namespace std;
template <class T>
class lList;
template <class T>
class Node
{
    T data;
    Node *next;

public:
    Node(T data = 0)
    {
        this->data = data;
        next = nullptr;
    }
    friend class lList<T>;
};

inline int checkInteger(string value)
{
    for (char i : value)
        if (!isdigit(i) && i != '-')
            return 0;
    return 1;
}

template <class T>
class lList
{
    Node<T> *head;

public:
    lList()
    {
        head = nullptr;
    }

    // ---- Insertion ------
    void insertAtBegin(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
            head = ptr;
        else
        {
            ptr->next = head;
            head = ptr;
        }
    }

    void insertAtEnd(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        Node<T> *p = head;
        if (head == nullptr)
            head = ptr;
        else
        {
            while (p->next != nullptr)
                p = p->next;
            p->next = ptr;
        }
    }

    void insertAtValue(T value, T data)
    {
        Node<T> *ptr = new Node<T>(data);
        Node<T> *p = head;
        if (head == nullptr)
            head = ptr;
        else
        {
            while (p->data != value)
            {
                p = p->next;
                if (p == nullptr)
                {
                    cout << "Value not Founded!\n";
                    return;
                }
            }
            ptr->next = p->next;
            p->next = ptr;
        }
    }

    void insertAtBeforeValue(T value, T data)
    {
        Node<T> *ptr = new Node<T>(data);
        Node<T> *p = head, *q;
        if (head == nullptr)
            head = ptr;
        else
        {
            while (p->data != value)
            {
                q = p;
                p = p->next;
                if (p == nullptr)
                {
                    cout << "Value not Founded!\n";
                    return;
                }
            }
            ptr->next = q->next;
            q->next = ptr;
        }
    }

    void insertrAtPosition(int position, T data)
    {
        Node<T> *ptr = new Node<T>(data);
        Node<T> *p = head;
        int c = 1;
        if (head == nullptr)
            head = ptr;
        else
        {
            while (c != position)
            {
                p = p->next;
                if (p == nullptr)
                {
                    cout << "Position out of Range!\n";
                    return;
                }
                c++;
            }
            ptr->next = p->next;
            p->next = ptr;
        }
    }
    void insertAtBeforePosition(int position, T data)
    {
        Node<T> *ptr = new Node<T>(data);
        Node<T> *p = head, *q;
        int c = 1;
        if (head == nullptr)
            head = ptr;
        else
        {
            while (c != position)
            {
                q = p;
                p = p->next;
                if (p == nullptr)
                {
                    cout << "Position out of Range!\n";
                    return;
                }
                c++;
            }
            ptr->next = q->next;
            q->next = ptr;
        }
    }

    // ----- Deletion ----
    void deletionAtBegin()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty!\n";
            return;
        }
        Node<T> *p = head;
        head = p->next;
        free(p);
    }

    void deletionAtEnd()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty!\n";
            return;
        }
        Node<T> *p = head, *q;
        while (p->next != nullptr)
        {
            q = p;
            p = p->next;
        }
        q->next = nullptr;
        free(p);
    }

    void deletionAtValue(T data)
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty!\n";
            return;
        }
        Node<T> *p = head, *q;
        while (p->data != data)
        {
            q = p;
            p = p->next;
            if (p == nullptr)
            {
                cout << "Value not Founded!\n";
                return;
            }
        }
        q->next = p->next;
        free(p);
    }

    void deletionAtPosition(int position)
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty!\n";
            return;
        }
        Node<T> *p = head, *q;
        int c = 1;
        while (c != position)
        {
            q = p;
            p = p->next;
            if (p == nullptr)
            {
                cout << "Position out of Range!\n";
                return;
            }
            c++;
        }
        q->next = p->next;
        free(p);
    }

    void deletionAtEndofValue(T data)
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty!\n";
            return;
        }
        Node<T> *p = head, *q = head, *r;
        int c = 1, a;
        while (p->next != nullptr)
        {
            if (p->data == data)
                a = c;
            c++;
            p = p->next;
        }
        c = 1;
        while (c != a)
        {
            r = q;
            q = q->next;
            c++;
        }
        r->next = q->next;
        free(q);
    }
    void deletionAtEndValue(T data, int position)
    {
        if (head == nullptr)
            cout << "Linked List is Empty!\n";
        else
        {
            Node<T> *p = head, *q = head, *r;
            int c = 1, a = 0, count = 0;
            while (p != nullptr)
            {
                if (p->data == data)
                {
                    a = c;
                    count++;
                    if (count == position)
                        break;
                }
                p = p->next;
                c++;
            }
            if (a == 0)
            {
                cout << "Element not found!\n";
                return;
            }
            else
            {
                c = 1;
                while (c != a)
                {
                    r = q;
                    q = q->next;
                    c++;
                }
                r->next = q->next;
                free(q);
            }
        }
    }

    void reversel()
    {
        Node<T> *p, *q, *r;
        p = head;
        q = p->next;
        p->next = nullptr;
        r = q->next;
        while (q->next != nullptr)
        {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        head = q;
    }

    void sorted()
    {
        Node<T> *p = head, *q;
        T temp;
        while (p->next != nullptr)
        {
            q = p->next;
            while (q != nullptr)
            {
                if (p->data > q->data)
                {
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
                q = q->next;
            }
            p = p->next;
        }
    }

    int search(T data)
    {
        int count = 1;
        Node<T> *p = head;
        while (p->data != data)
        {
            p = p->next;
            count++;
        }
        return count;
    }

    
    void operator+(lList<T> &ll1)
    {
        Node<T> *s = nullptr;
        Node<T> *r = new Node<T>();
        Node<T> *p = head;
        Node<T> *q = ll1.head;
        lList<T> ll;
        ll.head = r;
        while (p != nullptr)
        {
            cout << "Element : " << p->data << endl;
            p = p->next;
        }
        while (q != nullptr)
        {
            cout << "Element : " << q->data << endl;
            q = q->next;
        }
        while (p != nullptr && q != nullptr)
        {
            if (p->data < q->data)
            {
                r->data = p->data;
                p = p->next;
                r->next = p;
            }
            else
            {
                r->data = q->data;
                q = q->next;
                r->next = q;
            }
            if (head == nullptr)
            {
                head = r;
            }
            else
            {
                s->next = r;
            }
            s = r;
        }
        while (r != nullptr)
        {
            cout << "Element : " << r->data << endl;
            r = r->next;
        }

    }

    void display()
    {
        Node<T> *p = head;
        if(p == nullptr){
            cout<<"Linked List is Empty!\n";
            return;
        }
        while (p != nullptr)
        {
            cout << "Element : " << p->data << endl;
            p = p->next;
        }
    }
};

inline int get()
{
    string str;
    int option;
    while (true)
    {
        cin >> str;
        if (checkInteger(str))
        {
            option = atoi(str.c_str());
            break;
        }
        else
            cout << "Invalid Input!\ntry agian!\n";
    }
    return option;
}

int main()
{
    lList<int> l;
    lList<int> l1, l2;

    int n, option, value, element;
    string str;
    while (true)
    {
        cout << "Choose Any One : \n"
             << "1.Insert\n"
             << "2.Deletion\n"
             << "3.Reverse\n"
             << "4.Sorted\n"
             << "5.Merging\n"
             << "6.Search\n"
             << "7.Display\n"
             << "0.Exits\n";
        while (true)
        {
            n = get();
            if (n >= 0 && n < 9)
                break;
            else
                cout << "Enter correct option!\n";
        }
        if (n == 1)
        {
            while (true)
            {
                cout << "Choose Any One : \n"
                     << "1.Insert At Begin\n"
                     << "2.Insert At End\n"
                     << "3.Insert At Value\n"
                     << "4.Insert At Before Value\n"
                     << "5.Insert At Position\n"
                     << "6.Display\n"
                     << "0.Exits\n";
                while (true)
                {
                    option = get();
                    if (option >= 0 && option < 7)
                        break;
                    else
                        cout << "Enter correct option!\n";
                }
                if (option == 1)
                {
                    cout << "Enter number : ";
                    value = get();
                    l.insertAtBegin(value);
                }
                else if (option == 2)
                {
                    cout << "Enter number : ";
                    value = get();
                    l.insertAtEnd(value);
                }
                else if (option == 3)
                {
                    cout << "Enter number : ";
                    value = get();
                    cout << "Enter Element which after insert : ";
                    element = get();
                    l.insertAtValue(element, value);
                }
                else if (option == 4)
                {
                    cout << "Enter number : ";
                    value = get();
                    cout << "Enter Element which after insert : ";
                    element = get();
                    l.insertAtBeforeValue(element, value);
                }
                else if (option == 5)
                {
                    cout << "Enter number : ";
                    value = get();
                    cout << "Enter Position which after insert : ";
                    element = get();
                    l.insertrAtPosition(element, value);
                }
                else if (option == 6)
                    l.display();
                else
                    break;
            }
        }
        else if (n == 2)
        {
            while (true)
            {
                cout << "Choose Any One : \n"
                     << "1.Deletion At Begin\n"
                     << "2.Deletion At End\n"
                     << "3.Deletion At Value\n"
                     << "4.Deletion At End of Value\n"
                     << "5.Deletion At Position\n"
                     << "6.Display\n"
                     << "0.Exits\n";
                while (true)
                {
                    option = get();
                    if (option >= 0 && option < 7)
                        break;
                    else
                        cout << "Enter correct option!\n";
                }
                if (option == 1)
                {
                    l.deletionAtBegin();
                }
                else if (option == 2)
                    l.deletionAtEnd();
                else if (option == 3)
                {
                    cout << "Enter Value : ";
                    value = get();
                    l.deletionAtValue(value);
                }
                else if (option == 4)
                {
                    cout << "Enter Value : ";
                    value = get();
                    l.deletionAtEndofValue(value);
                }
                else if (option == 5)
                {
                    cout << "Enter Position : ";
                    value = get();
                    l.deletionAtPosition(value);
                }
                else if (option == 6)
                    l.display();
                else
                    break;
            }
        }
        else if (n == 3)
        {
            l.reversel();
            cout << "Reverse Complete\n";
        }
        else if (n == 4)
        {
            l.sorted();
            cout << "Complete Sorted\n";
        }
        
        else if (n == 5)
        {
            cout << "Pending Process!\n";
            
        }
        else if (n == 6)
        {
            cout << "Enter Position : ";
            value = get();
            cout<<"Position of Element is : "<<l.search(value);
        }
        else if (n == 7)
        {
            l.display();
        }
        else if (n == 0)
            break;
    }
    return 0;
}