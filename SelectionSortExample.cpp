#include <iostream>
using namespace std;

const int NUM_PRODUS = 9;
const int TITLE_SIZE = 26;
const int DESC_SIZE = 12;
const int MIN_PRODNUM = 914;
const int MAX_PRODNUM = 922;

//Functions prototypes
int getProdNum()
{
	int prodNum;
	cout << "Enter the item's product number:\n";
	cin >> prodNum;

	// Validate the product number entered by the user.
	while (prodNum < MIN_PRODNUM || prodNum > MAX_PRODNUM)
	{
		cout << "Enter the product number in the range of " << MIN_PRODNUM;
		cout << "through " << MAX_PRODNUM << ".\n";
		cin >> prodNum;
	}
	return prodNum;
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
		else {
			first = middle + 1;
		}
	}
	return position;

}

void BubbleSort(int array[], int size)
{
	int temp;
	bool swap;

	do
	{
		swap = false;

		for (int i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}
void selectionSort(int array[], int size)
{
	int startScan, minIndex, minValue;

	for (int startScan = 0; startScan < size - 1; startScan++)
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


void displayProd(char title[][TITLE_SIZE], char desc[][DESC_SIZE], double price[], int index)
{
	cout << "Title :" << title[index] << endl;
	cout << "Description :" << desc[index] << endl;
	cout << "Price :" << price[index] << endl;
}
int main()
{
	int id[NUM_PRODUS] =
	{ 915, 914, 916, 921, 918, 919, 922,
	  917, 920
	};

	char desc[NUM_PRODUS][DESC_SIZE] =

	{ "Book", "Audio CD", "DVD",
		"Book", "Audio CD", "DVD",
		"Book", "Book", "Audio CD"
	};

	char title[NUM_PRODUS][TITLE_SIZE] =
	{ "Six Steps to Leadership",
		"Six Steps to Leadership",
		"The Road to Excellence",
		"Seven Lessons of Quality",
		"Seven Lessons of Quality",
		"Seven Lessons of Quality",
		"Teams Are Made, Not Born",
		"Leadership for the Future",
		"Leadership for the Future"
	};

	double prices[NUM_PRODUS] = { 12.95, 14.95, 18.95, 16.95, 21.95,
		31.95, 14.95, 14.95, 16.95 };

	int prodNum;
	int index;
	char again;

	//Unsorted list
	cout << "Unsorted List of ids.\n";
	for (int i = 0; i < NUM_PRODUS; i++)
	{
		cout << id[i] << endl;
	}

	cout << endl;
	cout << "Sorted List of ids.\n";

	selectionSort(id, NUM_PRODUS);
	//Sorted list.
	for (int i = 0; i < NUM_PRODUS; i++)
	{
		cout << id[i] << endl;
	}

	do
	{
		prodNum = getProdNum();

		index = BinarySearch(id, NUM_PRODUS, prodNum);

		if (index == -1)
		{
			cout << "We Don't have the product at the moment!" << endl;
		}
		else {
			displayProd(title, desc, prices, index);
		}
		cout << "Would you like to look up another product? (y/n) ";
		cin >> again;

	} while (again == 'y' || again == 'Y');

	return 0;
}