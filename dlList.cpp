#include <iostream>
using namespace std;
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
    int option;
    while (true)
    {
        cin >> str;
        if (check(str))
        {
            option = atoi(str.c_str());
            break;
        }
        else
            cout << "Invalid \ntry again!\n";
    }
    return option;
}

template <class T>
class dlList;

template <class T>
class Node
{
    T data;
    Node *prev;
    Node *next;

public:
    Node(T data)
    {
        this->data = data;
        prev = nullptr;
        next = nullptr;
    }
    friend class dlList<T>;
};

template <class T>
class dlList
{
    Node<T> *head;

public:
    dlList()
    {
        head = nullptr;
    }
    void insertAtBegin(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
            head = ptr;
        else
        {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
    }

    void insertAtEnd(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (head == nullptr)
            head = ptr;
        else
        {
            Node<T> *p = head;
            while (p->next != nullptr)
                p = p->next;
            p->next = ptr;
            ptr->prev = p;
        }
    }

    void insertAtPosition(int position, T data)
    {
        int count = 1;
        Node<T> *ptr = new Node<T>(data);
        Node<T> *p = head;
        while (p != nullptr)
        {
            if (count == position)
                break;
            count++;
            p = p->next;
        }
        ptr->next = p->next;
        p->next->prev = ptr;
        p->next = ptr;
        ptr->prev = p;
    }

    void insertAtValue(T value, T data)
    {
        Node<T> *ptr = new Node<T>(data);
        Node<T> *p = head;
        while (p->data != value)
            p = p->next;
        ptr->next = p->next;
        p->next->prev = ptr;
        p->next = ptr;
        ptr->prev = p;
    }

    void reverse()
    {
        Node<T> *p = head, *q = p->next;
        // // p->next
        // // p->prev = p->next;
        // // p->next = nullptr;
        // // p = p->prev;
        // // q = q->next;
        // while (p != nullptr){
        //     p->next = p->prev;
        //     p->prev = q;
        //     // swap(p->next,p->prev);
        //     p = p->prev;
        //     q = q->next;
        //     cout<<p->data<<endl;
        // }
        //     // cout<<p->data<<endl;
        // head->next = nullptr;
        // head = p;
        // head->next = nullptr;
    }

    void deletionAtBegin()
    {
        Node<T> *p = head;
        if (head == nullptr)
        {
            cout << "Doubly Linked List is Empty!\n";
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
            delete p;
        }
    }

    void deletionAtEnd()
    {
        Node<T> *p = head;
        if (head == nullptr)
        {
            cout << "Doubly Linked List is Empty!\n";
        }
        else
        {
            while (p->next != nullptr)
                p = p->next;
            p->prev->next = nullptr;
            delete p;
        }
    }

    void deletionAtValue(T value)
    {
        Node<T> *p = head;
        if (head == nullptr)
        {
            cout << "Doubly Linked List is Empty!\n";
        }
        else
        {
            while (p->data != value)
            {
                if (p->next == nullptr)
                {
                    cout << "Element not found!\n";
                    return;
                }
                p = p->next;
            }
            if (p->next != nullptr)
            {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
            }
            else
                deletionAtEnd();
        }
    }
    void deletionAtPosition(int position)
    {
        Node<T> *p = head;
        int c = 1;
        if (head == nullptr)
        {
            cout << "Doubly Linked List is Empty!\n";
            return;
        }
        while (c != position)
        {
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
        else if (p->next != nullptr)
        {
            p->prev->next = p->next;
            p->next->prev = p->prev;
            delete p;
        }
        else
            deletionAtEnd();
    }

    void display()
    {
        Node<T> *p = head;
        if (p == nullptr)
        {
            cout << "Doubly Linked List is Empty!\n";
            return;
        }
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
    dlList<int> l;
    l.insertAtBegin(34);
    l.insertAtBegin(67);
    l.insertAtBegin(89);
    l.insertAtEnd(67);
    l.insertAtEnd(50);
    l.insertAtEnd(20);
    l.display();
    // l.reverse();
    // l.deletionAtBegin();
    // l.deletionAtEnd();
    // l.deletionAtValue(67);
    // l.deletionAtValue(20);
    // l.deletionAtValue(36);
    // l.deletionAtPosition(8);
    // l.display();
}

//     int num, op, value, p;
//     while (true)
//     {
//         cout << "Choose any one : \n"
//              << "1.Insertion at Begin\n"
//              << "2.Insertion at End\n"
//              << "3.Insertion at Position\n"
//              << "4.Insertion ar After Value\n"
//              << "5.Deletion at Begin\n"
//              << "6.Deletion at End\n"
//              << "7.Deletion at Position\n"
//              << "8.Deletion at value\n"
//              << "9.Reverse\n"
//              << "10.Display\n"
//              << "0.Exit\n";
//         op = get();
//         if (op == 1)
//         {
//             cout << "Enter Element : ";
//             num = get();
//             l.insertAtBegin(num);
//         }
//         else if (op == 2)
//         {
//             cout << "Enter Element : ";
//             num = get();
//             l.insertAtEnd(num);
//         }
//         else if (op == 3)
//         {
//             cout << "Enter Element : ";
//             num = get();
//             cout << "Enter Position : ";
//             p = get();
//             l.insertAtPosition(p, num);
//         }
//         else if (op == 4)
//         {
//             cout << "Enter Element : ";
//             num = get();
//             cout << "Enter Value : ";
//             value = get();
//             l.insertAtValue(value, num);
//         }
//         else if (op == 5)
//             l.deletionAtBegin();
//         else if (op == 6)
//             l.deletionAtEnd();
//         else if (op == 7)
//         {
//             cout << "Enter Position : ";
//             p = get();
//             l.deletionAtPosition(p);
//         }
//         else if (op == 8)
//         {
//             cout << "Enter Value : ";
//             value = get();
//             l.deletionAtValue(value);
//         }
//         else if (op == 9)
//         {
//             // l.reverse();
//             cout << "Pending!\n";
//         }
//         else if (op == 10)
//             l.display();
//         else if (op == 0)
//             break;
//         else
//             cout << "Invalid Option!\n";
//     }
//     return 0;
// }