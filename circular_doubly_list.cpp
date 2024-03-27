#include <iostream>
using namespace std;

class cdl;

class Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        data = d;
        next = nullptr;
        prev = nullptr;
    }

    friend class cdl;
};

class cdl
{
    Node *front;
    Node *rear;

public:
    cdl()
    {
        front = nullptr;
        rear = nullptr;
    }
    void enqueue(int d)
    {
        Node *ptr = new Node(d);
        if (!front)
        {
            front = ptr;
            rear = ptr;
            front->prev = rear;
            rear->next = front;
        }
        else
        {
            ptr->next = rear->next;
            ptr->prev = rear;
            rear->next = ptr;
            rear = ptr;
            front->prev = rear;
        }
    }

    int dqueue(){
        if(!front){
            cout<<"Queue is Empty!\n";
            return -1;
        }
        else{
            Node *p = front;
            int value = front->data;
            front = front->next;
            front->prev = rear;
            rear->next = front;
            delete p;
            return value;
        }
    }

    void display()
    {
        Node *p = front;
        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != front);
        cout << endl;
        Node *q = rear;
        do
        {
            cout << q->data << " ";
            q = q->prev;
        } while (q != rear);
        cout<<endl;
    }
};

int main()
{
    cdl c;
    c.enqueue(45);
    c.enqueue(23);
    c.enqueue(67);
    c.enqueue(90);
    c.enqueue(35);
    c.display();
    cout<<c.dqueue()<<" "<<endl;
    c.display();
    c.enqueue(69);
    c.enqueue(29);
    c.display();
    cout<<c.dqueue()<<" "<<endl;
    c.display();
    return 0;
}