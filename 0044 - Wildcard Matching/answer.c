#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isMatch(char const *s, char const *p)
{
	char const *star = NULL;
	char const *ss = s;

	while (*s)
	{
		if ((*p == '?') || (*p == *s))
		{
			s++;
			p++;
			continue;
		}

		if (*p == '*')
		{
			star = p++;
			ss = s;
			continue;
		}

		if (star)
		{
			p = star + 1;
			s = ++ss;
			continue;
		}

		return (false);
	}

	while (*p == '*')
		p++;

	return (!*p);
}

#define TEST_MATCH(s, p)	do {\
	{\
		bool b = isMatch(s, p);\
		printf("\"%s\" match /%s/ -> %d\n", s, p, b);\
	}\
} while(0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	TEST_MATCH("aa", "a");
	TEST_MATCH("aa", "*");
	TEST_MATCH("cb", "?a");
	TEST_MATCH("adceb", "*a*b");
	TEST_MATCH("acdcb", "a*c?b");
	TEST_MATCH("bbbababbbbabbbbababbaaabbaababbbaabbbaaaabbbaaaabb", "*b********bb*b*bbbbb*ba");
	TEST_MATCH("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb");

	return (EXIT_SUCCESS);
}
