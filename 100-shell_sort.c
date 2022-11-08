#include "sort.h"
/**
  *shell_sort - sort array using shell_sort with knuth sequence
  *@array: array to be sorted
  *@size: size of array
  *
  *Return: void
  */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t interval = 1, i, j;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] >= temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}

		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
