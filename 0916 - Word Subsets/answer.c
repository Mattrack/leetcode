#include <stdlib.h>

#define MAX(a, b)	((a) > (b) ? (a) : (b))

void count(char const *s, int *count)
{
	for (; s && *s; s++)
		count[*s - 'a'] += 1;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **wordSubsets(char **A, int ASize, char **B, int BSize, int *returnSize)
{
	char **result = NULL;
	int bmax[26] = {0};
	int i;

	for (i = 0; i < BSize; i++)
	{
		int bcount[26] = {0};
		int j;

		count(B[i], bcount);
		for (j = 0; j < 26; j++)
			bmax[j] = MAX(bmax[j], bcount[j]);
	}

	*returnSize = 0;
	for (i = 0; i < ASize; i++)
	{
		int acount[26] = {0};
		int j;
		int success = 1;

		count(A[i], acount);
		for (j = 0; success && j < 26; j++)
		{
			if (acount[j] < bmax[j])
				success = 0;
		}

		if (success)
		{
			result = realloc(result, sizeof(*result) * (*returnSize + 1));
			result[*returnSize] = A[i];
			*returnSize += 1;
		}
	}

	return (result);
}
