#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
	char **ret = calloc(n, sizeof(*ret));
	int i;

	*returnSize = n;
	for (i = 1; i <= n; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
			ret[i - 1] = strdup("FizzBuzz");
		else if (i % 3 == 0)
			ret[i - 1] = strdup("Fizz");
		else if (i % 5 == 0)
			ret[i - 1] = strdup("Buzz");
		else
		{
			ret[i - 1] = calloc(1, 11);
			sprintf(ret[i - 1], "%d", i);
		}
	}

	return (ret);
}
