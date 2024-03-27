#include <iostream>
using namespace std;

class parenthesis
{
    char *s;
    string str;
    int capicity, top;

public:
    parenthesis(string str)
    {
        this->str = str;
        this->capicity = str.length();
        s = new char[capicity];
        top = -1;
    }
    int parenthises()
    {
        for (char i : str)
        {
            if (i == '(' || i == '{' || i == '[')
            {
                // push(i);
                s[++top] = i;
            }
            else if (i == ')')
                if (s[top] == '(')
                    // pop();
                    top--;
                else
                {
                    cout << "Wrong ')' Parenthesis Matching!\n";
                    return 0;
                }
            else if (i == '}')
                if (s[top] == '{')
                    // pop();
                    top--;
                else
                {
                    cout << "Wrong '}' Parenthesis Matching!\n";
                    return 0;
                }
            else if (i == ']')
                if (s[top] == '[')
                    // pop();
                    top--;
                else
                {
                    cout << "Wrong ']' Parenthesis Matching!\n";
                    return 0;
                }
        }
        if (top != -1)
        {
            cout << "Wrong Parenthesis Matching!\n";
            return 0;
        }
        return 1;
    }
};


int main()
{
    string str;
    cout << "Enter String : ";
    cin >> str;
    parenthesis s(str);
    if (s.parenthises())
        cout << "Complete Parenthesis Matching!\n";
    return 0;
}