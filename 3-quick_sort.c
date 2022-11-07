#include "sort.h"

/**
 * swap - swap a and b
 * @a: First number
 * @b: Second number
 * Return: Void
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * pivot - Get the pivot of the array
 * @array: The unsorted array.
 * @size: The length of the array
 * @low: The left side of the pivot
 * @high: The right side of the pivot
 * Return: the final partition length
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	for (j = i = low; i < high; i++)
	{
		if (array[i] <= *pivot)
		{
			if (j < i)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			j++;
		}
	}
	if (array[j] > *pivot)
	{
		swap(array +j, pivot);
		print_array(array, size);
	}
	return (j);
}
/**
 * Lomuto - Lomuto partition scheme.
 * @array: The unsorted array.
 * @size: The length of the array
 * @low: The left size of hte pivot
 * @high: The right side of the pivot
 * Return: Void
 */
void Lomuto(int *array, size_t size, int low, int high)
{
	int pa;

	if (high - low > 0)
	{
		pa = partition(array, size, low, high);

		Lomuto(array, size, low, pa - 1);
		Lomuto(array, size, pa + 1, high);
	}
}

/**
 * quick_sort - sort an array using quick_sort algorithm
 * @array: The unsorted array.
 * @size: The length of the array
 */
void quick_sort(int *array, size_t size)
{
	if (0 >= size)
		return;

	Lomuto(array, size, 0, size - 1);
}
