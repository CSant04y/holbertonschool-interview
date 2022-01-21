#include "sort.h"


/**
 * merge_sort - This Sort an array in acending order with merge sort.
 * @array: This is pointer to begining of array
 * @size: This the size of the array
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t middle, i;
	int left[MAX], right[MAX];

	if (!array || size < 2)
		return;

	for (i = 0, middle = size / 2; i < middle; i++)
		left[i] = array[i];

	for (i = middle; i < size; i++)
		right[i - middle] = array[i];

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(array, left, right, size);
}
/**
 * merge - This merges tow arrays
 *
 * @array: array with numbers
 * @L: left sub array
 * @R: Right sub array
 * @size: Size of the array
 * Return: nothing
 */
void merge(int *array, int *L, int *R, size_t size)
{
	int i, j, k, l_len, r_len;

	i = j = k = 0;
	l_len = size / 2;
	r_len = size - l_len;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(L, l_len);
	printf("[right]: ");
	print_array(R, r_len);
	while (i < l_len && j < r_len)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < l_len)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < r_len)
	{
		array[k] = R[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array, size);
}
