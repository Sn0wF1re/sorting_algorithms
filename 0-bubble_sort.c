#include "sort.h"

/**
 *bubble_sort - sort array in ascending order using bubble sort
 *@array: array to be sorted
 *@size: size of array
 *
 *Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

}
