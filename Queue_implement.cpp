#include <iostream>
using namespace std;
template <class T>
class queue
{
    T *q;
    int cap, f, r, size;

public:
    queue(int c)
    {
        this->cap = c;
        q = new T[cap];
        f = 0;
        r = 0;
        size = 0;
    }
    bool isFull()
    {
        return (size == cap);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void push(T data)
    {
        if (isFull())
        {
            cout << "Stack is Full!\n";
            return;
        }
        q[r] = data;
        r = (r + 1) % cap;
        size++;
    }

    T pop()
    {
        static T var;
        if (isEmpty())
        {
            cout << "Stack is Empty!\n";
            return var;
        }
        var = q[f];
        f = (f + 1) % cap;
        size--;
        return var;
    }

    int sizeq()
    {
        return size;
    }

    void display()
    {
        int j = f;
        for (int i = 0; i < size; i++)
        {
            cout << q[j] << " ";
            j = (j + 1) % cap;
        }
        cout<<endl;
    }
};

int main()
{
    int op, ele, max,i=0;
    cout << "Enter Maximum size of Stack : ";
    cin >> max;
    queue<int> q(max);
    while (i<1000)
    {
        i++;
        cout << "Choose any one : \n"
             << "1.Insert\n"
             << "2.Delete\n"
             << "3.Size\n"
             << "4.is Full\n"
             << "5.is Empty\n"
             << "6.Display\n"
             << "0.Exits\n";
        cin >> op;
        if (op == 1)
        {
            cout << "Enter Element : ";
            cin >> ele;
            q.push(ele);
        }
        else if (op == 2)
            cout << "Remove : " << q.pop() << endl;
        else if (op == 3)
            cout << "Size : " << q.sizeq() << endl;
        else if (op == 4)
            cout << "Full : " << q.isFull() << endl;
        else if (op == 5)
            cout << "Empty : " << q.isEmpty() << endl;
        else if (op == 6)
            q.display();
        else if (op == 0)
            break;
        else
            cout << "Invalid Option!\n";
    }
    return 0;
}