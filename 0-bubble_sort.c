#include "sort.h"

/**
 * bubble_sort - function that sorts using bubble sort
 * @array: array in use
 * @size: size of the array in use
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size, i;
	int checker, temp;

	while (array && n > 1)
	{
		checker = 0;
		for (i = 0; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				print_array(array, size);
				checker = i;
			}
		}
		n = checker;
	}
}
