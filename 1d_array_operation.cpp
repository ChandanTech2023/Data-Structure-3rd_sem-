#include <iostream>
using namespace std;
/*
Q2. Write a c++ program to perform follwing operations in one dimensional array of int
i. sum of elements of array
ii. average of elements of array
iii. find smallest and largest element of array
iv. insertion and deletion on particular index
v. linear and binary searching of element in array
vi. concenating and merging()
concenating -> not sorted only join two array
merging -> join two array with sorted
*/
class MyArray
{
    int *arr;
    int size, n;

public:
    MyArray(int max = 20)
    {
        this->n = max;
        arr = new int[n];
    }
    ~MyArray() { delete[] arr; }
    inline int checkInteger(string value)
    {
        for (char i : value)
            if (!isdigit(i) && i != '-')
                return 0;
        return 1;
    }
    void getArray()
    {
        string str;
        do
        {
            do
            {
                cout << "Enter size of array : ";
                cin >> str;
                if (checkInteger(str))
                    break;
                cout << "Invalid Input!\ntry Again!\n";
            } while (true);
            size = atoi(str.c_str());
            if (size < 1)
                cout << "Enter correrct size of array!\n";
        } while (size < 1);
        cout << "Enter all elemets of array1 : \n";
        for (int i = 0; i < size; i++)
        {
            do
            {
                cin >> str;
                if (checkInteger(str))
                    break;
                cout << "Invalid Input!\ntry Again!\n";
            } while (true);
            arr[i] = atoi(str.c_str());
        }
    }
    int *twoSumArray(MyArray ma)
    {
        MyArray ma1;
        string str;
        cout << "Enter all elements of array2 : \n";
        for (int i = 0; i < size; i++)
        {
            do
            {
                cin >> str;
                if (checkInteger(str))
                    break;
                cout << "Invalid Input!\ntry Again!\n";
            } while (true);
            ma.arr[i] = atoi(str.c_str());
        }
        ma1.arr = new int[size];
        for (int i = 0; i < size; i++)
            ma1.arr[i] = arr[i] + ma.arr[i];
        return arr;
    }
    int sumArray()
    {
        int s = 0;
        for (int i = 0; i < size; i++)
            s += arr[i];
        return s;
    }
    int averageArray()
    {
        int average = 0;
        for (int i = 0; i < size; i++)
            average += arr[i];
        return (average / size);
    }
    int smallestElement()
    {
        int small = arr[0];
        for (int i = 0; i < size; i++)
            if (small > arr[i])
                small = arr[i];
        return small;
    }
    int largeElement()
    {
        int large = arr[0];
        for (int i = 0; i < size; i++)
            if (large < arr[i])
                large = arr[i];
        return large;
    }
    void insertion()
    {
        int element, index;
        cout << "Enter element what do you insert : ";
        cin >> element;
        cout << "Enter index fo inserted element : ";
        cin >> index;
        if (size < n)
        {
            for (int i = size; i > index; i--)
                arr[i + 1] = arr[i];
            arr[index] = element;
        }
        else
            cout << "Please matain size of array before insertion\n";
    }
    void deletion()
    {
        int element, index;
        string str;
        do
        {
            cout << "Enter element what do you insert : ";
            cin >> str;
            if (checkInteger(str))
                break;
            cout << "Invalid Input!\ntry Again!\n";
        } while (true);
        element = atoi(str.c_str());
        for (int i = 0; i < size; i++)
        {
            if (element == arr[i])
                index = i;
        }
        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];
    }
    int linearSearching()
    {
        int index, element;
        string str;
        do
        {
            cout << "Enter element what do you search on array : ";
            cin >> str;
            if (checkInteger(str))
                break;
            cout << "Invalid Input!\ntry Again!\n";
        } while (true);
        element = atoi(str.c_str());
        for (int i = 0; i < size; i++)
        {
            if (element == arr[i])
            {
                index = i;
                break;
            }
        }
        return index;
    }
    int binarySearching()
    {
        int element, first = 0, last = size - 1, mid;
        string str;
        do
        {
            cout << "Enter element what do you search on array : ";
            cin >> str;
            if (checkInteger(str))
                break;
            cout << "Invalid Input!\ntry Again!\n";
        } while (true);
        element = atoi(str.c_str());
        while (mid != 0)
        {
            mid = (first + last) / 2;
            if (arr[mid] == element)
                return mid;
            else if (arr[mid] < element)
                first = mid - 1;
            else if (arr[mid] > element)
                last = mid + 1;
        }
        return mid;
    }
    void shorting()
    {
        int temp;
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                if (arr[i] > arr[j])
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                }
    }

    void SelectionShort()
    {
        /*
        6   4   9   8   3   0   2   5
        |   |   |   |   |   |   |   |
        0   1   2   3   4   5   6   7
        ->  ->  ->  ->  ->  ->  ->  -
        | --> 1st sorted value
        */
        int midIndex, temp;
        for (int i = 0; i < size; i++)
        {
            midIndex = i;
            for (int j = i + 1; j < size; j++)
            {
                if (arr[j] < arr[midIndex])
                    midIndex = j;
            }
            swap(arr[i], arr[midIndex]);
        }
    }

    void BubbleSort()
    {
        /*
        6   4   9   8   3   0   2   5
        |   |   |   |   |   |   |   |
        0   1   2   3   4   5   6   7
        <-  <-  <-  <-  <-  <-  <-  <-
            strating from last  <---|
        */
        int flag, temp;
        for (int i = 0; i < size; i++)
        {
            flag = 0;
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    flag++;
                }
            }
            if (flag == 0)
                break;
        }
    }

    /*
    6   4   9   8   3   0   2   5
    |   |   |   |   |   |   |   |
    0   1   2   3   4   5   6   7

    */
    void InsertionShort()
    {
        int j, temp;
        for (int i = 0; i < size; i++)
        {
            j = i - 1;
            temp = arr[i];
            while (j >= 0 && temp < arr[j])
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
    MyArray &concanteArray(MyArray &ma, MyArray &ma1)
    {
        ma.getArray();
        ma1.size = ma.size + size;
        ma1.arr = new int[ma1.size];
        for (int i = 0; i < ma1.size; i++)
        {
            if (i < size)
                ma1.arr[i] = arr[i];
            else
                ma1.arr[i] = ma.arr[i - size];
        }
        return ma1;
    }
    void merging()
    {
        MyArray ma1, ma3, ma2;
        ma2 = concanteArray(ma1, ma3);
        ma2.shorting();
        cout << "After Merging : \n";
        ma2.display();
    }

    MyArray &operator+(MyArray a1)
    {
        MyArray *ma;
        ma = new MyArray();
        if (!size)
        {
            ma->size = a1.size;
            ma->arr = a1.arr;
            return *ma;
        }
        if (!a1.size)
        {
            ma->size = size;
            ma->arr = arr;
            return *ma;
        }

        ma->size = size + a1.size;
        int i = 0, j = 0, k = 0;
        while (i != size && j != a1.size)
        {
            if (arr[i] <= a1.arr[j])
            {
                ma->arr[k] = arr[i];
                i++;
            }
            else
            {
                ma->arr[k] = a1.arr[j];
                j++;
            }
            k++;
        }
        if (i == size)
        {
            for (int l = j; l < a1.size; l++)
            {
                ma->arr[k] = a1.arr[l];
                k++;
            }
        }
        else
        {
            for (int l = i; l < size; l++)
            {
                ma->arr[k] = a1.arr[l];
                k++;
            }
        }
        return *ma;
    }

    void digonal_matrix()
    {
        int **darr;
        darr = new int *[size];
        for (int i = 0; i < size; i++)
            darr[i] = new int[size];

        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                    darr[i][j] = arr[i];
                else
                    darr[i][j] = 0;
            }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                cout << darr[i][j] << " ";
            cout << endl;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main()
{
    MyArray ma, ma1, ma2, ma3;
    int n;
    string str;

    ma.getArray();

    do
    {
        do
        {
            cout << "Choose any one : \n"
                 << "0.Exit\n"
                 << "1.sum of elements of array\n"
                 << "2.average of elements of array\n"
                 << "3.find smallest element of array\n"
                 << "4.find largest element of array\n"
                 << "5.insertion on particular index\n"
                 << "6.deletion on particular index\n"
                 << "7.linear searching of element in array\n"
                 << "8.binary searching of element in array\n"
                 << "9.Short array\n"
                 << "10.concatinating and\n"
                 << "11.merging() \n"
                 << "12.Selection  Short Array\n"
                 << "13.Bubble Sort Array \n"
                 << "14.Insertion Sort Array \n"
                 << "15.Array to Digonal Matrix \n";
            cin >> str;
            if (ma.checkInteger(str))
                break;
            cout << "Invalid Input!\ntry Again!\n";
        } while (true);
        n = stoi(str);
        if (n > 16 || n < 0 && n != 0)
            cout << "Enter valid input!\n";
        else if (n == 0)
            break;
    } while (n > 15 || n < 0);

    if (n == 1)
        cout << "Sum of all elements of array is : " << ma.sumArray() << endl;
    else if (n == 2)
        cout << "Average of all elements of array is : " << ma.averageArray() << endl;
    else if (n == 3)
        cout << "Smaleest element of array is : " << ma.smallestElement() << endl;
    else if (n == 4)
        cout << "Largest element of array is : " << ma.largeElement() << endl;
    else if (n == 5)
    {
        cout << "Before Insertion\n";
        ma.insertion();
        cout << "After Insertion : \n";
        ma.display();
    }
    else if (n == 6)
    {
        cout << "Before Deletion\n";
        ma.deletion();
        cout << "After Deletion : \n";
        ma.display();
    }
    else if (n == 7)
        cout << "Index of element in array usinf linear searching : " << ma.linearSearching() << endl;
    else if (n == 8)
        cout << "Index of element in array using binary searching : " << ma.binarySearching() << endl;
    else if (n == 9)
    {
        ma.shorting();
        cout << "After sorted : \n";
        ma.display();
    }
    else if (n == 10)
    {
        ma1 = ma.concanteArray(ma2, ma3);
        cout << "After Concentaing : \n";
        ma1.display();
    }
    else if (n == 11)
    {
        MyArray ma1;
        ma1.getArray();
        ma2 = (ma + ma1);
        ma2.display();
    }
    else if (n == 12)
    {
        ma.SelectionShort();
        cout << "After Sorting : \n";
        ma.display();
    }
    else if (n == 13)
    {
        ma.BubbleSort();
        cout << "After Sorting : \n";
        ma.display();
    }
    else if (n == 14)
    {
        ma.InsertionShort();
        cout << "After Sorting : \n";
        ma.display();
    }
    else if(n == 15){
        ma.digonal_matrix();
    }
    else if (n == 0)
        cout << "Thanks!\n";
    else
        cout << "Invalid Option Selected!\n";
    return 0;
}