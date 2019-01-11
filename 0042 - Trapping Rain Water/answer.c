#include <stdlib.h>

#define MIN(a, b)	((a) < (b) ? (a) : (b))

int trap(int *h, int heightSize)
{
	int water = 0;
	int *rights = calloc(heightSize, sizeof(*rights));
	int max;
	int i;

	for (max = 0, i = heightSize - 1; i >= 0; i--)
	{
		rights[i] = max;
		if (h[i] > max)
			max = h[i];
	}

	for (max = 0, i = 0; i < heightSize; i++)
	{
		if (h[i] > max)
		{
			max = h[i];
			continue;
		}

		if (h[i] < max && h[i] < rights[i])
			water += MIN(max, rights[i]) - h[i];
	}

	free(rights);
	return (water);
}
