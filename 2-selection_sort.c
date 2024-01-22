#include "sort.h"

/**
 * selection_sort - function to sort with insertion sort
 * @array: array in use
 * @size: size of the array in use
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
