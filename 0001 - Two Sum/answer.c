#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
	int *res = calloc(2, sizeof(*res));
	int i;

	for (i = 0; i < numsSize; i++)
	{
		int j;

		for (j = i + 1; j < numsSize; j++)
		{
			if (nums[i] + nums[j] == target)
			{
				res[0] = i;
				res[1] = j;
				return (res);
			}
		}
	}

	return (res);
}
