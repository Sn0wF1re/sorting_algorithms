#include "sort.h"
#include <math.h>

/**
 * swap - swap a and b
 * @a: First integer
 * @b: Second integer
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
 * siftDown - swap the left or the right node with the parent at the heap
 * @array: The unsorted arrray
 * @size: The length of the array
 * @start: The start of the root
 * @end: The end of the root
 * Return: Void
 */
void siftDown(int *array, size_t size, int start, int end)
{
	int root, child, swp;

	root = start;
	while (floor(root * 2 + 1) <= end)
	{
		child = floor(root * 2 + 1);
		swp = root;

		if (array[swp] < array[child])
			swp = child;

		if (child + 1 <= end && array[swp] < array[child + 1])
			swp = child + 1;

		if (swp == root)
			return;
		else if (swp != root)
		{
			swap(array + root, array + swp);
			print_array(array, size);
			root = swp;
		}
	}
}

/**
 * heapify - Build the heap in array a so that largest  value is at the root
 * @array: The unsorted array
 * @size: The length of the array
 * @count: The length of the array
 * Return: Void
 */
void heapify(int *array, size_t size, int count)
{
	int start = floor((count - 2) / 2);

	while (start >= 0)
	{
		siftDown(array, size, start, count - 1);
		start--;
	}
}

/**
 * heap_sort - Sort an array using heap sort algorithm
 * @array: The unsorted array
 * @size: The length of the array
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{
	int end;

	if (size <= 0)
		return;
	heapify(array, size, size);

	end = size - 1;
	while (end > 0)
	{
		swap(array + end, array + 0);
		print_array(array, size);
		end--;
		siftDown(array, size, 0, end);
	}
}
