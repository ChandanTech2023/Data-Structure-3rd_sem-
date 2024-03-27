#include <iostream>
using namespace std;

template <class T>
class myStack
{
    T *s;
    int capicity, top;

public:
    myStack(int cap)
    {
        this->capicity = cap;
        s = new T[capicity];
        top = -1;
    }

    bool isFull()
    {
        return (top == capicity - 1);
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    void push(T data)
    {
        if (isFull())
        {
            cout << "Stack is Full!\n";
            return;
        }
        else
            s[++top] = data;
    }
    T pop()
    {
        static T var;
        if (isEmpty())
        {
            cout << "Stack is Empty!\n";
            return var;
        }
        else
        {
            T ele = s[top];
            top--;
            return ele;
        }
    }
    int size()
    {
        return (top + 1);
    }
    T topElement()
    {
        static T var ;
        if (isEmpty())
        {
            cout << "Stack is Empty!\n";
            return var;
        }
        else
            return s[top];
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
            cout << s[i] << " ";
        cout << endl;
    }
};

int main()
{
    int cap, op;
    string ele;
    cout << "Enter Max size of Stack : ";
    cin >> cap;
    myStack<string> stc(cap);
    while (true)
    {
        cout << "Choose any one : \n"
             << "1.push\n"
             << "2.pop\n"
             << "3.isEmpty\n"
             << "4.isFull\n"
             << "5.Top Element\n"
             << "6.Stack Size\n"
             << "7.Dsiplay\n"
             << "0.Exit\n";
        cin >> op;
        if (op == 1)
        {
            cout << "Enter Element : ";
            cin >> ele;
            stc.push(ele);
        }
        else if (op == 2)
            cout << "Pop Element : " << stc.pop() << endl;
        else if (op == 3)
            cout << "Empty : 1 / Not Empty : 0 -> " << stc.isEmpty() << endl;
        else if (op == 4)
            cout << "Full : 1 / Not Full : 0 -> " << stc.isFull() << endl;
        else if (op == 5)
            cout << "Top Element : " << stc.topElement() << endl;
        else if (op == 6)
            cout<<"Size of Stack : "<<stc.size();
        else if (op == 7)
            stc.display();
        else if (op == 0)
            break;
        else
            cout << "Invalid Option selected!\n";
    }
    return 0;
}