#include <iostream>
using namespace std;

int BinarySearch(int arr[], int elements, int value)
{
	bool found = false;
	int first = 0,
		last = elements - 1,
		middle;
	int pos = -1;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (arr[middle] == value)
		{
			found = true;
			pos = middle;
		}
		else if (arr[middle] > value)
		{
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}
	return pos;
}

int main()
{
	const int size = 5;
	int number[size] = { 23, 56, 78, 89, 100 };
	int results;
	int value;

	cout << "Elements:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << number[i] << endl;
	}

	cout << "Search the position of any element!" << endl;
	cin >> value;

	results = BinarySearch(number, size, value);

	if (results == -1)
	{
		cout << "The element you are looking for is not  available!" << endl;
	}
	else {

		cout << "The element you are looking for is available on " << results << endl;


	}
	return 0;
}