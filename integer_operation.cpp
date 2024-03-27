#include <iostream>
#include <cmath>
using namespace std;
/*
Q1. Write a c++ programe perform the follwing operation in a integer
i. sum of digites of given integer
ii. reversing its digits of given integer
iii. factorial of integer
iv. fibonnaci series upto inetger
v. prime number upto that integer
v. multiplication of two digits by passing object through out

HINT:
class MyInt{
int n;   -> only one variable in class of private access
};
1 constructor and destructor
make multiple variable in only allow under method

maintain
brute force(solving only question)
optimal solve(solving all question using minimum time , minimum use of memory, less storage , sort code) -> not complusory
*/
class MyInt
{
    int n;

public:
    MyInt(int a = 0)
    {
        n = a;
    }
    ~MyInt() {}
    int sumDigits()
    {
        int r = n, s = 0;
        while (r != 0)
        {
            s += r % 10;
            r = r / 10;
        }
        return s;
    }
    int reversingDigits()
    {
        int a = n, r = 0;
        while (a != 0)
        {
            r = r * 10 + a % 10;
            a = a / 10;
        }
        return r;
    }
    long factorial()
    {
        long fac = 1;
        if (n > 0)
            for (int i = 2; i < n; i++)
            {
                fac *= i;
            }
        else
            return -1;
        return fac;
    }
    // time consuming , not optimal
    int fibonacci()
    {
        int n1 = 0, n2 = 1, n3 = 0;
        if (n == 1 && n > 0)
            return n1;
        while (n3 < n)
        {
            cout << n1 << " ";
            n3 = n1 + n2;
            n1 = n2;
            n2 = n3;
        }
        return n1;
    }
    void prime()
    {
        int p = n;
        bool c = true;
        if (n > 0)
            for (int i = 1; i <= p; i++)
            {
                c = true;
                for (int j = 2; j <= i / 2; j++)
                {
                    if (i % j == 0)
                    {
                        c = false;
                        break;
                    }
                }
                if (c)
                    cout << i << " ";
                else if (!(i < p))
                    break;
            }
        else
            cout << "-1";
    }
    MyInt multiplication(MyInt a)
    {
        MyInt x(0);
        x.n = n * a.n;
        return x;
    }
    void display()
    {
        cout << n;
    }
};
int menu()
{
    int num;
    string value;
    cout << "Select any one : \n"
         << "1. Sum of Digits\n"
         << "2. Reversing of Digits\n"
         << "3. Factorial \n"
         << "4. Fibonnaci series upto given integer\n"
         << "5. Prime number upto given integer\n"
         << "6. Mulitplication of two numbers \n";
    cin >> value;
    for (char i : value)
        if (!isdigit(i))
            return 0;
    num = atoi(value.c_str());
    return num;
}

int main()
{
    int n, a, b;
    string num, value;
    try
    {
        cout << "Enter number : ";
        cin >> num;
        for (char i : num)
            if (!isdigit(i) && i != '-')
                throw "Invalid Input!";
        n = atoi(num.c_str());
    }
    catch (const char *e)
    {
        cout << e << endl;
        exit(0);
    }
    MyInt m(n);
    a = menu();
    if (a)
    {
        if (a == 1)
            cout << "Sum of Digits : " << m.sumDigits() << endl;
        else if (a == 2)
            cout << "Reversing of Digits : " << m.reversingDigits() << endl;
        else if (a == 3)
            if (n <= 20)
                cout << "Factorial of given integer : " << m.factorial() << endl;
            else
                cout << "Please enter value of n is less than or equal to 20\n";
        else if (a == 4)
            cout << "Fibonnaci number upto given integer : " << m.fibonacci() << endl;
        else if (a == 5)
        {
            cout << "Prime number upto given integer : ";
            m.prime();
            cout << endl;
        }
        else if (a == 6)
        {
            cout << "Enter 2nd number : ";
            cin >> b;
            MyInt m1(b), m2(0);
            m2 = m.multiplication(m1);
            cout << "Multiplication of two number : ";
            m2.display();
            cout << endl;
        }
        else
        {
            cout << "Please enter correct number!\n";
        }
    }
    else
        cout << "Invalid Input\n";

    return 0;
}