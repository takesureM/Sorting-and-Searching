#include <iostream>
using namespace std;

int linearSearch(int list[], int numElements, int value)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < numElements && !found)
    {
        if (list[index] == value)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

int binarySearch(const int list[], int numElem, int value)
{
    int first = 0,
        last = numElem - 1,
        middle,
        pos = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2;

        if (list[middle] == value)
        {
            found = true;
            pos = middle;
        }
        else if (list[middle] > value)
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return pos;
}

void bubbleSort(int array[], int size)
{
    bool swap;
    int temp;

    do
    {
        swap = false;

        for (int count = 0; count < (size - 1); count++)
        {
            if (array[count] > array[count + 1])
            {
                temp = array[count];
                array[count] = array[count + 1];
                array[count + 1] = temp;
                swap = true;
            }
        }

    } while (swap);
}

void selectionSort(int array[], int size)
{
    int startScan, minValue, minIndex;

    for ( startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }

}
int main()
{
    cout << "Hello World!\n";
    int const number = 5;
    int list[number];
    int results;
    int num;

    cout << "Enter numbers:\n";
    cout << "Before sort\n";
    for (int i = 0; i < number; i++)
    {
        cin >> list[i];
    }
    
    selectionSort(list, number);

    cout << "after sort\n";
    for (int i = 0; i < number; i++)
    {
        cout << list[i] << endl;
    }
    
    cout << "Enter number you are searching:\n";
    cin >> num;
    results = binarySearch(list, number, num);
    
    if (results == -1)
    {
        cout << "Sorry you did not score 60 marks\n";
    }
    else
    {
        cout << results << endl;
    }

    
        
  
    return 0;
}
