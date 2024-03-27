#include <iostream>
using namespace std;

template <class T>
class clqueue;

template <class T>
class Node
{
    T data;
    Node<T> *next;

public:
    Node(int d)
    {
        data = d;
        next = nullptr;
    }
    friend class clqueue<T>;
};

template <class T>
class clqueue
{
    Node<T> *front;
    Node<T> *rear;
    int size;

public:
    clqueue()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    void enqueue(T data)
    {
        Node<T> *ptr = new Node<T>(data);
        if (front == nullptr)
        {
            front = ptr;
            rear = ptr;
            rear->next = front;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = front;
        }
        size++;
    }

    T dqueue()
    {
        if (front == nullptr)
        {
            cout << "Queue is Empty!\n";
            return false;
        }
        else
        {
            T value = front->data;
            Node<T> *w = front;
            front = front->next;
            size--;
            delete w;
            return value;
        }
    }

    int sizeQeue()
    {
        return size;
    }

    T frontEle()
    {
        if (front == nullptr)
        {
            static T v;
            return v;
        }
        else
            return front->data;
    }
    T raerEle()
    {
        if (rear == NULL)
        {
            static T v;
            return v;
        }
        else
            return rear->data;
    }

    bool isEmpty()
    {
        if (front == nullptr)
            return true;
        else
            return false;
    }
    void display()
    {
        Node<T> *p = front;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != front);
        cout << endl;
    }
};

int main()
{
    clqueue<int> q;
    int n, option;
    while (true)
    {
        cout << "Choose any one : \n1.enqueues \n2.dqueues \n3.Size \n4.Front Element \n5.Rear Element \n6.Is Empty \n7.Display \n0.Exits\n";
        cin >> option;
        if (option == 1)
        {
            cout << "Enter Element : ";
            cin >> n;
            q.enqueue(n);
        }
        else if (option == 2)
            cout << "Dqueues Element : " << q.dqueue() << endl;
        else if (option == 3)
            cout << "Size of Queue : " << q.sizeQeue() << endl;
        else if (option == 4)
            cout << "Front Element : " << q.frontEle() << endl;
        else if (option == 5)
            cout << "Rear Element : " << q.raerEle() << endl;
        else if (option == 6)
            cout << "Empty : " << q.isEmpty() << endl;
        else if (option == 7)
            q.display();
        else if (option == 0)
            break;
        else
            cout << "Invalid Option\n";
    }
    return 0;
}