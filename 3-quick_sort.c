#include "sort.h"

/**
 * swap - partitions an array for Lomuto's quicksort
 * @array: array to sort
 * @size: size of the array
 * @i: first index of array to swap
 * @j: second index of array to swap
 */
void swap(int *array, size_t size, int i, int j)
{
	int temp;

	if (i == j)
		return;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
 * partition - partitions an array for Lomuto's quicksort
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

	for (j = lo; j < hi; j++)
		if (array[j] <= pivot)
			swap(array, size, ++i, j);

	swap(array, size, ++i, hi);
	return (i);
}

/**
 * qs_lomuto - sorts an array using Lomuto's quicksort
 * @array: array to sort
 * @size: size of the array
 * @lo: beginning index of array to sort
 * @hi: ending index of array to sort
 */
void qs_lomuto(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo >= hi || lo < 0)
		return;

	p = partition(array, size, lo, hi);
	qs_lomuto(array, size, lo, p - 1);
	qs_lomuto(array, size, p + 1, hi);
}

/**
 * quick_sort - function to sort with quick sort
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	qs_lomuto(array, size, 0, size - 1);
}
