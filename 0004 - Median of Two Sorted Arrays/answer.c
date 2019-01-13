#include <stdlib.h>
#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int *arr;
	int s = nums1Size + nums2Size;
	int i, i1 = 0, i2 = 0;

	arr = malloc(s * sizeof(*arr));
	for (i = 0; i < s; i++)
		if (i1 < nums1Size && (i2 >= nums2Size || nums1[i1] < nums2[i2]))
			arr[i] = nums1[i1++];
		else
			arr[i] = nums2[i2++];

	if (s % 2 == 0)
		return ((float)(arr[s / 2 - 1] + arr[s / 2]) / 2.0);

	return (arr[s / 2]);
}

#define ARRAY_SIZE(a)	(sizeof(a) / sizeof(a[0]))

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	int nums1[] = {1, 3};
	int nums2[] = {2};
	double res;

	res = findMedianSortedArrays(nums1, ARRAY_SIZE(nums1), nums2, ARRAY_SIZE(nums2));
	printf("Res -> %f\n", res);

	return (EXIT_SUCCESS);
}

