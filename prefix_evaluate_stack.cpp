#include <iostream>
using namespace std;
class stack
{
    int *arr;
    int top, size,cap;

public:
    stack(int s)
    {
        cap = s;
        size = 0;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == cap;
    }
    void push(int data)
    {
        if (isFull())
            return;
        arr[++top] = data;
        size++;
    }
    int pop()
    {
        if (isEmpty())
            return -1;
        int d = arr[top];
        top--;
        size--;
        return d;
    }
    int display(){
        if(size > 1){
            cout<<"Your input is invalid\n";
            return -1;
        }else{
            return arr[0];
        }
    }
};

void prefix(string str){
    stack s(int(str.length()/4)*3);
    string newstr = "";
    int x1,x2;
    for (char i : str+" ")
    {
        if(i != ' '){
            newstr += i;
        }
        else if(newstr == "+"){
            x1 = s.pop();
            x2 = s.pop();
            s.push(x2+x1);
            newstr = "";
        }
        else if(newstr == "-"){
            x1 = s.pop();
            x2 = s.pop();
            s.push(x2-x1);
            newstr = "";
        }
        else if(newstr == "x"){
            x1 = s.pop();
            x2 = s.pop();
            s.push(x2*x1);
            newstr = "";
        }
        else if(newstr == "/"){
            x1 = s.pop();
            x2 = s.pop();
            s.push(int(x2/x1));
            newstr = "";
        }
        else{
            s.push(stoi(newstr));
            newstr = "";
        }
    }
    cout<<"After Evaluate this prefix equation {"<<str<<"} : "<<s.display()<<endl;
}

int main()
{
    string p;
    cout<<"Enter prefix evaluate : ";
    getline(cin,p);
    prefix(p);
    return 0;
}