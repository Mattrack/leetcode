#include <string.h>

int lengthOfLongestSubstring(char* s)
{
	int start_i;
	int max_count = 0;
	char appear[127] = {0};

	for (start_i = 0; s[start_i]; start_i++)
	{
		int count;

		memset(appear, 0, 127);

		for (count = 0; s[start_i + count]; count++)
		{
			if (appear[s[start_i + count]] != 0)
				break;
			appear[s[start_i + count]] = 1;
		}
		max_count = count > max_count ? count : max_count;
	}

	return (max_count);
}
