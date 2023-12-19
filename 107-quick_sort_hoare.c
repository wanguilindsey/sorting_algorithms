#include <stdio.h>
#include "sort.h"

void swap_elements(int *array, size_t size, ssize_t i, ssize_t j);
ssize_t hoare_partition_helper(int *array, size_t size, ssize_t low, ssize_t high);
void hoare_partition(int *array, size_t size, ssize_t low, ssize_t high);

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *                    Quick sort algorithm (Hoare partition scheme).
 *
 * @array: The array to be sorted.
 * @size:  The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_partition(array, size, 0, size - 1);
}

/**
 * hoare_partition - Hoare partition scheme for Quick sort.
 *
 * @array: The array to be partitioned.
 * @size:  The size of the array.
 * @low:   The starting index of the partition.
 * @high:  The ending index of the partition.
 */
void hoare_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		ssize_t pivot_index = hoare_partition_helper(array, size, low, high);

		hoare_partition(array, size, low, pivot_index - 1);
		hoare_partition(array, size, pivot_index + 1, high);
	}
}

/**
 * hoare_partition_helper - Helper function for Hoare partition scheme.
 *
 * @array: The array to be partitioned.
 * @size:  The size of the array.
 * @low:   The starting index of the partition.
 * @high:  The ending index of the partition.
 *
 * Return: The index of the pivot after partitioning.
 */
ssize_t hoare_partition_helper(int *array, size_t size,
		ssize_t low, ssize_t high)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap_elements(array, size, i, j);
	}
}

/**
 * swap_elements - Swaps two elements in an array and prints the array.
 *
 * @array: The array containing elements.
 * @size:  The size of the array.
 * @i:     The index of the first element to swap.
 * @j:     The index of the second element to swap.
 */
void swap_elements(int *array, size_t size, ssize_t i, ssize_t j)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;

	print_array(array, size);
}
