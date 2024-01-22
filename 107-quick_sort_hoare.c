#include "sort.h"

/**
 * swap - partitions an array for hoare's quicksort
 * @array: array to sort
 * @size: size of the array
 * @i: first index of array to swap
 * @j: second index of array to swap
 */
void swap(int *array, size_t size, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * partition - partitions an array for hoare's quicksort
 * @array: array to sort
 * @size: size of the array
 * @lo: beginning index of array to sort
 * @hi: ending index of array to sort
 * Return: index of the chosen index for the partition
 */
int partition(int *array, size_t size, int lo, int hi)
{
	int pivot, i, j;

	pivot = array[hi];
	i = lo - 1;
	j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		swap(array, size, i, j);
	}
}

/**
 * qs_hoare - sorts an array using hoare's quicksort
 * @array: array to sort
 * @size: size of the array
 * @lo: beginning index of array to sort
 * @hi: ending index of array to sort
 */
void qs_hoare(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo >= 0 && hi >= 0 && lo < hi)
	{
		p = partition(array, size, lo, hi);
		qs_hoare(array, size, lo, p - 1);
		qs_hoare(array, size, p, hi);
	}
}

/**
 * quick_sort_hoare - function to sort with quick sort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size)
		return;
	qs_hoare(array, size, 0, size - 1);
}
