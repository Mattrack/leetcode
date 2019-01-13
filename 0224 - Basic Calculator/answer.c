#include <stdlib.h>
#include <stdio.h>

static char *_calc_rec(char const *s, int *res)
{
	int mul = 1;

	for (;s && *s; s++)
	{
		if (*s >= '0' && *s <= '9')
			*res += strtol(s, (char **)&s, 10) * mul;

		if (*s == '+')
			mul = 1;
		else if (*s == '-')
			mul = -1;

		if (*s == '(')
		{
			int n = 0;

			s = _calc_rec(s + 1, &n);
			*res += n * mul;
		}
		else if (*s == ')')
			return ((char *)s);
	}

	return ((char *)s);
}

int calculate(char const *s)
{
	int res = 0;

	_calc_rec(s, &res);

	return (res);
}

#define TEST_CALC(s)	do {\
	{\
		int res = calculate(s);\
		printf("%s\n\t= %d\n", s, res);\
	}\
} while (0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	TEST_CALC("1 + 1");
	TEST_CALC(" 2-1 + 2 ");
	TEST_CALC("(1+(4+5+2)-3)+(6+8)");
	TEST_CALC("2147483647");
	TEST_CALC("1-(5)");
	TEST_CALC("2-(5-6)");

	return (EXIT_SUCCESS);
}
