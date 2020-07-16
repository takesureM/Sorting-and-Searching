#include <iostream>
using namespace std;

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

int main()
{
	return 0;
}