#include <iostream>
using namespace std;

template <class T>
class My2dArray
{
    T **arr;
    int row, col;
    // T element;

public:
    My2dArray(int row, int col)
    {
        this->row = row;
        this->col = col;
        arr = new T *[row];
        for (int i = 0; i < row; i++)
            arr[i] = new T[col];
    }
    ~My2dArray() { delete[] arr; }

    void getData()
    {
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                cout << "Enter element " << i << j << " : ";
                cin >> arr[i][j];
            }
    }

    void display()
    {
        cout << "Matrix Display : \n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    My2dArray operator+(My2dArray<T> &a1)
    {
        My2dArray<T> a2(row, col);
        if (row == a1.row && col == a1.col)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                    a2.arr[i][j] = arr[i][j] + a1.arr[i][j];
            }
        }
        return a2;
    }

    My2dArray operator*(My2dArray<T> &a1)
    {
        My2dArray<T> a2(row, a1.col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < a1.col; j++)
            {
                a2.arr[i][j] = 0;
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < a1.col; j++)
            {
                for (int k = 0; k < a1.row; k++)
                {
                    a2.arr[i][j] += arr[i][k] * a1.arr[k][j];
                }
            }
        }

        return a2;
    }

    My2dArray transpose()
    {
        My2dArray<T> a1(row, col);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a1.arr[i][j] = 0;
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a1.arr[i][j] = arr[j][i];
            }
        }
        return a1;
    }
};

int main()
{
    int r1, c1, r2, c2, n;
    cout << "Enter number of row : ";
    cin >> r1;
    cout << "Enter number of column : ";
    cin >> c1;
    My2dArray<int> m(r1, c1);
    m.getData();
    cout << "Choose any one : \n"
         << "1.Add 2 Matrices \n"
         << "2.Multiplication 2 Matrices \n"
         << "3.Transpose\n";
    cin >> n;
    if (n == 1)
    {
        cout << "Enter number of row : ";
        cin >> r2;
        cout << "Enter number of column : ";
        cin >> c2;
        if (r1 == r2 && c1 == c2)
        {
            My2dArray<int> m1(r2, c2), m2(r1, c2);
            m1.getData();
            m2 = m + m1;
            cout << "Matrix 1: \n";
            m.display();
            cout << "Matrix 2: \n";
            m1.display();
            cout << "Sum of Matrices : \n";
            m2.display();
        }
    }
    else if (n == 2)
    {
        cout << "Enter number of row : ";
        cin >> r2;
        cout << "Enter number of column : ";
        cin >> c2;
        if (c1 == r2)
        {
            My2dArray<int> m1(r2, c2), m2(c1, r2);
            m1.getData();
            m2 = m * m1;
            cout << "Matrix 1: \n";
            m.display();
            cout << "Matrix 2: \n";
            m1.display();
            cout << "Multiplication of Matrices : \n";
            m2.display();
        }
    }
    else if (n == 3)
    {
        My2dArray<int> m1(r1, c1);
        m1 = m.transpose();
        m.display();
        m1.display();
    }
    return 0;
}