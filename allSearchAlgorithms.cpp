#include <iostream>
using namespace std;

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int FibonocciSort(int array[], int n, int value)
{
    int j, f, t, f1, f2, mid;

    while (fibo(j) <= n)
    {
        j++;
    }

    // find the lowest the value;
    f = fibo(j);
    f1 = fibo(j - 1);
    f2 = fibo(j - 2);
    mid = f1 - mid + 1;

    while (value != array[mid]) // if not found;
    {
        if (mid < 0 || value > array[mid])
        {
            if (f1 == 0)
                return -1;
            mid = mid + f2;
            f1 = f1 - f2;
            f2 = f2 - f1;

        }
        else
        {
            if (f2 == 1)
                return -1;
            mid = mid - f2;
            t = f1 - f2;
            f1 = f2;
            f2 = t;

        }
    }
    return mid;
}

int createIndex(int index[], int isize, int A[], int asize)
{
    int i, j;
    for (i = 0, j = 0; i < asize, i += 8; j++)
    {
        index[j] = A[i];

    }
    index[j] = A[asize - 1];
}

int IndexSeqSearch(int index[], int isize, int A[], int asize, int value)
{
    int i = 0, j = 0, pos = 0;
    int high = 0, low = 0;

    if (value > index[isize - 1] && value < index[0])

        return -1;
    while (i < isize)
    {
        if (value == index[i])
        {
            pos = 8 * i;
            return pos;
        }
        else if (value == index[i])
        {
            low = 8 * (i - 1);
            high = 8 * i;
            break;
        }
        else
        {
            low = 8 * i;
            high = 8 * (i + 1);
        }
        i++;
    }


    while (low < high)
    {
        if (value == A[i])

            return low;
        else
            low++;
    }
    return -1;
}

int linearSearch(int list[], int elements, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < elements && !found)
    {
        if (list[index] == value)
        {
            found = true;
            position = index;
            break;
        }
        index++;
    }
    return position;
}

int BinarySearch(int array[], int elements, int value)
{
    int first = 0,
        last = elements - 1,
        middle;
    int position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle] == value)
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }

    }
    return position;
}

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}

int FibonacciSearch(int list[], int elements, int value)
{
    int f1, f2, mid, f, t, j;
    j = 1;

    while (fibo(j) <= elements)
    {
        j++;
    }

    // find lowest value
    f = fibo(j);
    f1 = fibo(j - 2);
    f2 = fibo(j - 3);
    mid = elements - f1 + 1;


    while (value != list[mid]) // if not find;
    {
        if (mid < 0 || value > list[mid])
        {
            if (f1 == 1)
                return -1;
            mid = mid + f2;
            f1 = f1 - f2;
            f2 = f2 - f1;
        }
        else
        {
            if (f2 == 0)
                return -1;
            mid = mid - f2;
            t = f1 - f2;
            f1 = f2;
            f2 = t;
        }
    }
    return mid;
}
int main()
{
    const int SIZE = 18;
    int numbers[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                        8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                        1005231, 6545231, 3852085, 7576651, 7881200, 4581002
    };
    int AccountNumber = 0;

    int results = FibonacciSearch(numbers, SIZE, 7881200);
    cout << "Enter Your Charge Account Number" << endl;
    cin >> AccountNumber;

    if (results == -1)
    {
        cout << "Sorry the charge account number is invalid!" << endl;
    }
    else
    {

        cout << "The charge account number is valid!" << endl;
    }

    return 0;
}

